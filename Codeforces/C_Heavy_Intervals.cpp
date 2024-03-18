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
    set<int>  r;
    vector<int> l;

    for(int i = 0; i <n ; i++){
        int x; cin >> x;
        l.push_back(x);
    }

    for(int  i = 0; i < n; i++){
        int x; cin >> x;
        r.insert(x);
    }
    
    sort(all(l));
    vector<int> val;

    for(int i = n-1; i >= 0; i--){
        auto it = r.upper_bound(l[i]);
        if(it != r.end()){
           r.erase(*it);
           val.push_back((*it) -  l[i]);
        } 
    }

    vector<int> c(n);
    for(auto &x : c) cin >> x;

    sort(all(c)); reverse(all(c));
    sort(all(val));

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += val[i]*c[i];
    }
  
    cout << ans << endl;

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