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

    int n, a[6];
    for(auto &i : a) cin >> i;

    vector<pair<int,int>> b;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(auto j : a){
            b.push_back({x-j,i});
        }
    }

    sort(all(b));

    int ans = b.back().first - b[0].first;
    vector<int> vis(n);
    int cnt = 0;


    for(int i = 0, j = 0; j < sz(b); j++){
        if(vis[b[j].second] == 0){
            cnt++;
        }
        vis[b[j].second]++;
        if(cnt == n){
            ans = min(ans,b[j].first - b[i].first);
        }

        while(i <= j && cnt == n){
            if(vis[b[i].second] == 1){
                cnt--;
            }
            vis[b[i].second]--;
            ans = min(ans,b[j].first - b[i].first);
            i++;
        }
    }

    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

