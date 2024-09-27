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

    int x = sqrt(n);
    if(x * x != n){
        cout << "No\n";return;
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            if(i == 0 || i == x - 1 || j == 0 || j == x - 1){
                if(s[i * x + j] == '0'){
                    cout << "No\n";return;
                }
            }else{
                if(s[i * x + j] == '1'){
                    cout << "No\n";return;
                }
            }
        }
    }
    cout << "Yes\n";

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
