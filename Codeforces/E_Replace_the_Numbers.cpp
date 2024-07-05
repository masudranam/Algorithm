#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 5e5 + 10;

void solve(){
    int n; cin >> n;
    vector<array<int,3>> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i][0];
        if(a[i][0] == 1){
            cin >> a[i][1];
        }else{
            cin >> a[i][1] >> a[i][2];
        }
    }

    vector<int> p(N);
    for(int i = 1; i < N; i++){
        p[i] = i;
    }

    vector<int> res;

    for(int i = n-1; i >= 0; i--){
        if(a[i][0] == 1){
            res.push_back(p[a[i][1]]);
        }else{
            p[a[i][1]] = p[a[i][2]];
        }
    }
    reverse(res.begin(),res.end());
    print(res);
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
