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
    int n, m; cin >> n >> m;
    vector<int> l(n),r(n);

    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }

    vector<ar<int,2>>seg;
    for(int i = 0; i < n; i++){
        if(l[i] == 1)continue;
        seg.push_back({l[i],1});
        seg.push_back({r[i]+1,-1});
    }
    sort(all(seg));
    int cur = 0, ans = 0;
    for(int i = 0; i < sz(seg); i++){
        cur += seg[i][1];
        ans = max(ans,cur);
    }
    seg.clear();
    
    for(int i = 0; i < n; i++){
        if(r[i] == m)continue;
        seg.push_back({l[i],1});
        seg.push_back({r[i]+1,-1});
    }
    sort(all(seg));

    cur = 0;
    for(int i = 0; i < sz(seg); i++){
        cur += seg[i][1];
        ans = max(ans,cur);
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

