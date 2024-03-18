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
   
    vector<ar<int,2>>v(n);
    for(int i = 0; i < n; i++){
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        v[i] = {l,b};
    }
    sort(all(v));
    vector<ar<int,2>> cur;

    for(auto x: v){
        if(sz(cur) && cur.back()[1] >= x[0]){
            cur.back()[1] = max(cur.back()[1],x[1]);
        }else{
            cur.push_back({x[0],x[1]});
        }
    }
    sort(all(cur));

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        int k = lower_bound(all(cur),ar<int,2>({x+1,0}))-cur.begin()-1;
        if(k >= 0){
            x = max(x,cur[k][1]);
        }
        cout<<x<<" \n"[i==q-1];
    }

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

