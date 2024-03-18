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
    string s; cin >> s;
    for(int i = 1; i < n; i++){
        if(s[i] > s[0]){
            cout<<"Yes\n";return;
        }
    }
    for(int i = 1; i < n;i++){
        if(s[i] != s[0])continue;
        string f = s.substr(0,i);
        string l = s.substr(i);
        if(l > f){
            cout<<"Yes\n";return;
        }
    }
    cout<<"No\n";

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

