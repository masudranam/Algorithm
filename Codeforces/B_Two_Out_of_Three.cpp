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
    vector<int> g[110];
    int cnt = 0;

    for(int i = 0; i < n; i++){
        int x;cin >> x;
        g[x].push_back(i);
    }
    for(int i = 1; i <= 100; i++)cnt += (sz(g[i]) > 1);
    if(cnt < 2){
        cout<<-1<<endl;
        return;
    }

    vector<int> ans(n,1);

    vector<int> v;
    for(int i = 1; i <= 100 && sz(v) < 2; i++){
            if(sz(g[i]) > 1)v.push_back(i);
    }
    ans[g[v[0]][0]] = 1;
    for(int i =1 ; i < sz(g[v[0]]); i++){
        ans[g[v[0]][i]] = 2;
    }


    ans[g[v[1]][0]] = 1;
    for(int i = 1; i < sz(g[v[1]]); i++){
        ans[g[v[1]][i]] = 3;
    }
    print(ans);


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

