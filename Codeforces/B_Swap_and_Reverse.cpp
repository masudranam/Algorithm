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
    int n, k;cin >> n >> k;

    string s; cin >> s;
    
    if(k%2 == 0){
        sort(all(s));
        cout<<s<<endl;return;
    }else{
        string f, sc;
        for(int i = 0; i < n; i++){
            if(i&1)sc+=s[i];
            else f+=s[i];
        }
        sort(all(sc)); sort(all(f));
        string ans;
        for(int i = 0; i < sz(sc);i++){
            ans += f[i];
            ans += sc[i];
        } 
        if(n&1)ans += f.back();
        cout<<ans<<endl;
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

