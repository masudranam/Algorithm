#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int res = 0, last = 0;

    vector<pair<int,int>> a;
    vector<array<int,3>> b;

    for(int i = 0; i < k; i++){
        int r, c; cin >> r >> c;
        a.push_back({c, -r});
        b.push_back({-r,c,i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mxr = 0;

    for(int i = 0; i < k; i++){
        if(-a[i].second <= last)continue;
        res += (-a[i].second - last)*(a[i].first - 1);
        last = max(last, -a[i].second);
    }
    if(last < n){
        res += (n - last) * m;
    }

    vector<int> ans(k);
    last = m+1;

    for(int i = 0; i < k; i++){
        if(b[i][1] < last){
            ans[b[i][2]] = 1;
        }
        last = min(last,b[i][1]);
    }

    cout << res << '\n';

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
