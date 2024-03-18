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
    string s; cin >> s;
    int n = sz(s);

    int tot = 0, mn = 0,srt = 0, us = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '+')tot++,us = max(us+1,1ll);
        else tot--,us--,srt--,mn = min(mn,srt);

        if(s[i] == '0'){
            if(tot <= 1 || us <= 0){
                cout<<"NO\n";return;
            }
            srt = 1;
        }else if(s[i] == '1'){
            if(srt >= 1){
                cout<<"NO\n";return;
            }
            
        }
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

