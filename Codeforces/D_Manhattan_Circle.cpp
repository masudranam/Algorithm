#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> x, y;
    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '#'){
                x.push_back(j+1);
                y.push_back(i+1);
            }
        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    cout << (y[0] + y.back()) / 2 <<' '<< (x[0] + x.back()) / 2 << '\n';
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

