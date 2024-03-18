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
    int n, m;
    cin >> n >> m;

    set<int> l;
    multiset<int> r;
    r.insert(n+1);

    map<int,vector<int>>mp;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        l.insert(x),r.insert(y);
        mp[x].push_back(y);
    }

    int ans = n*(n+1)/2;
    int last = 0;

    for(int x : l){
        auto it = r.lower_bound(x);
        int right = (n-*it+1);
        int left = right*(x-last-1);
        ans -= right;
        ans -= left;
        for(auto y: mp[x])r.erase(r.find(y));
        last = x;
    }
    cout<<ans<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

