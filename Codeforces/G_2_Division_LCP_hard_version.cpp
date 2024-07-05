#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> z_function (string s) {
   int n = (int) s.length();
   vector<int> z (n);
   int l = 0, r = 0;
   for (int i = 1; i < n; ++i) {
      if (i <= r)
         z[i] = min (r - i + 1, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
         ++z[i];
      if (i + z[i] - 1 > r)
         l = i, r = i + z[i] - 1;
   }
   return z;
}

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    string s; cin >> s;
    
    vector<int> z = z_function(s);
    vector<int> ans(n+1);

    for(int i = 1; i * i <= n; i++){
        int l = 0, r = n / i;
        while(r - l > 0){
            int m = (l + r + 1) / 2;
            int cnt = 1;
            for(int j = m; j < n;){
                if(z[j] >= m) j += m, cnt++;
                else j++;
            }
            if(cnt >= i) l = m;
            else r = m - 1;
        }
        ans[i] = l;

        int cur = 1;
        for(int j = i; j < n;){
            if(z[j] >= i) cur++, j += i;
            else j++;
        }
        ans[cur] = max(ans[cur], i);
    }

    for(int i = n-1; i >= 1; i--){
        ans[i] = max(ans[i], ans[i+1]);
    }

    for(int i = l; i <= r; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
