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
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    vector<int> x(m),y(m),z(m);

    for(int i = 0; i < m; i++){
        string s; cin >> s;
        cin >> x[i] >> y[i] >> z[i];
    }

    set<ar<int,3>> l, r;
    l.insert({0,0,0});
    r.insert({0,0,0});

    for(int i = 0; i < m/2; i++){
        set<ar<int,3>> t;
        for(auto it : l){
            t.insert({it[0] + x[i], it[1] + y[i], it[2] + z[i]});
        }
        for(auto it : t){
            l.insert(it);
        }
    }

    for(int i = m/2; i < m; i++){
          set<ar<int,3>> t;
        for(auto it : r){
            t.insert({it[0] + x[i], it[1] + y[i], it[2] + z[i]});
        }
        for(auto it : t){
            r.insert(it);
        }
    }

    for(auto it : l){
        ar<int,3> t = {a - it[0], b - it[1], c - it[2]};
        if(r.find(t) != r.end()){
            cout <<"POSSIBLE\n";return;
        }
    }

    cout <<"IMPOSSIBLE\n";

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

