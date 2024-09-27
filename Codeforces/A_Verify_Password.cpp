#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    bool ok = true;
    for(int i = 1; i < n; i++){
        if((s[i] >= '0' && s[i] <= '9') && (s[i-1]>='a' && s[i-1]<='z')){
            cout << "NO\n";return;
        }
    }
    for(int i = 1; i < n; i++){
        if((s[i] >= 'a' && s[i] <= 'z') && (s[i-1] >= '0' && s[i-1] <= '9'))continue;
        ok &= (s[i] >= s[i-1]);
    }
    if(ok)cout << "YES\n";
    else cout << "NO\n";

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

