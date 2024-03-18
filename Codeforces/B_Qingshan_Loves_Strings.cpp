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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    
    bool ok = 1;
    for(int i = 1; i < n; i++){
        ok&=(s[i]!=s[i-1]);
    }
    if(ok){
        cout<<"Yes\n";
        return;
    }

    ok = 1;
    for(int i = 1; i < m; i++){
        ok &= (t[i]!=t[i-1]);
    }
    if(!ok){
        cout<<"No\n";
        return;
    }

    for(int i = 1; i < n; i++){
        if(s[i]==s[i-1]){
            if(s[i] == '0' && (t[0] == '0'||t.back()=='0')){
                cout<<"No\n";return;
            }else if(s[i] == '1' && (t[0] == '1' || t.back() == '1')){
                cout<<"No\n";return;
            }
        }
    }
    cout<<"Yes\n";
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

