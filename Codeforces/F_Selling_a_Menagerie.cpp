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
    int n;
    cin >> n;
    vector<int> p(n+1),vis(n+1),vis1(n+1),a(n+1);
    set<ar<int,2>> st;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = a[i];
    }

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        st.insert({-x,i});
    }

    while(sz(st)){
        ar<int,2> b = *st.begin();
        st.erase(st.begin());
        if(vis1[p[b[1]]])continue;
        cout<<b[1]<<' ';
        vis1[p[b[1]]] = 1;
        vis[b[1]] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i])cout<<i<<' ';
    }
    cout<<endl;

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

