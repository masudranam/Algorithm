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
    vector<int> a(n);
    for(auto &x: a)cin >> x;

    int id = 0;
    vector<int> v;

    for(int i = 1;i < n; i++){
        if(a[i] > a[id]){
            v.push_back(i-id);
            id = i;
        }
    }
    if(sz(v) == 0){
        cout<<1<<endl;
        return;
    }
    v.push_back(1);

    n = sz(v);
    vector<int> sf(n+1);

    for(int i = n-2; i >= 0; i--){
        v[i] = (v[i]*v[i+1])%M;
        sf[i] = (v[i]+sf[i+1])%M;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans+sf[i])%M;
    }
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

