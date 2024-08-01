#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> p(n+1);
    for(int i = 1; i <= n;i++){
        cin >> p[i];
    }
    for(int i = 1; i <= n;i++){
        for(int j = i + 1; j <= n; j++){
            if(p[i] == j && p[j] == i){
                cout <<2 << endl;
                return;
            }
        }
    }
    cout << 3 << endl;
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

