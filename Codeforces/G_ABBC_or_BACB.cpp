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
        int tot = 0, mn = M, cnt = 0, ok = 0;
        int n = sz(s);
        for(int i = 0; i < n; i++){
            if(s[i] == 'A'){
                cnt++;
            }else{
                if(cnt)tot += cnt, mn = min(cnt,mn);
                cnt = 0;
                if(i && s[i-1] == 'B')ok = 1;
            }
        }
        tot += cnt;
        if(cnt)mn = min(cnt,mn);
        
        if(s[0] == 'B' || s.back() == 'B' || ok)cout<<tot<<endl;
        else cout<<max(0ll,tot-mn)<<endl;
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

