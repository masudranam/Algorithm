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
    vector<int> v(n);

    for(auto &i : v) cin >> i;
    vector<int> a{0},b{0};

    for(int i = 0; i < n; i++){
        if(a.back() != v[i]){
            a.push_back(v[i]);
        }else if(b.back() != v[i]){
            b.push_back(v[i]);
        }
    }
    
    cout << sz(a) + sz(b) - 2 << endl;
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

