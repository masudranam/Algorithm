#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n), ans(q);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<array<int,3>> query[n+1];

    for(int i = 0; i < q; i++){
        int s, d, k;
        cin >> s >> d >> k, s--;
        if(d > 300){
            for(int j = 0; j < k; j++){
                ans[i] += a[s + j*d] * (j + 1);
            }
        }else{
            query[d].push_back({s, k, i});
        }
    }

    for(int d = 1; d <= n; d++){
        if(query[d].empty()) continue;
        vector<int> s0(n),s1(n);

        for(int i = 0; i < n; i++){
            if(i >= d){
                s0[i] = s0[i - d];
                s1[i] = s1[i - d];
            }
            s0[i] += a[i];
            s1[i] += (i / d + 1) * a[i];
        }
        for(auto x : query[d]){
            int s = x[0], k = x[1], id = x[2];
            int res = s1[s + (k - 1) * d];
            int extra = s0[s + (k - 1) * d];
            if(s >= d){
                extra -= s0[s - d];
                res -= s1[s - d];
            }
            res += (extra * (-s / d));
            ans[id] = res;
        }
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
