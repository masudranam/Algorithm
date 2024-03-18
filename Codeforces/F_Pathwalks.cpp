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

vector<map<int,int>>mp;

int get(int x, int w){
    auto it = mp[x].lower_bound(w);
    if(it == mp[x].begin()) return 1;
    it--;
    return (it->second+1);
}

void solve(){
    int n, m;
    cin >> n >> m;
    mp.resize(n+1);
    int ans = 0;

    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        int val = get(a,w);
        if(get(b,w+1) > val)continue;
        mp[b][w] = max(mp[b][w],val);
        auto it = mp[b].upper_bound(w);
        while(it != mp[b].end() && it->second <= val){
            it = mp[b].erase(it);
        }
        ans = max(ans,val);
    }
    cout << ans << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

