#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;

    int ans = 0;

    for(int i = 0; i < n; i++){
        if(i % 2)continue;
        int cur = a[i], mn = a[i];
        for(int j = i + 1; j < n; j++){
            if(j % 2 == 0){
                cur += a[j];continue;
            }

            int l = max(0ll, cur - a[j]);
            int r = min(a[i], mn+1);
            //cout << j <<' ' << l <<' '<< r << endl;
            ans += max(0ll,(r - l));
            cur -= a[j];
            mn = min(mn,cur);
            if(cur < 0)break;
        }
    }

    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

