#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> s(n+1), a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        s[i+1] = s[i] ^ a[i];
    }

    int res = 0;
    for(int bit = 0; bit < 30; bit++){
        int pre = 0, suf = 0;
        for(int i = 0; i <= n; i++){
            suf += ((s[i] >> bit) & 1);
        }
        for(int i = 0; i < n; i++){
            pre += ((s[i] >> bit) & 1);
            suf -= ((s[i] >> bit) & 1);
            if(bit == __lg(a[i])){
                res += (suf * pre + (i + 1 - pre) * (n - i - suf));
            }
        }
    }
    cout << res << '\n';
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
