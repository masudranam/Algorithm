#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int k; cin >> k;

    vector<pair<int,int>> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i].second;
    }

    sort(a.begin(), a.end());

    int res = 0;
    int m = n / 2;

    for(int i = 0; i < n; i++){
        if(a[i].second){
          if(i >= m)res = max(res,a[i].first + k + a[m-1].first );
          else res = max(res, a[i].first + k + a[m].first);
        }
    }

    int l = 0, r = M * N;
    m = (n + 1) / 2;
    while(l < r){
        int m1 = (l + r + 1) / 2;
        int cnt = 0, tmp = k;

        for(int i = n - 2; i >= 0; i--){
            if(a[i].second){
                if(tmp >= m1 - a[i].first){
                    cnt++;
                    tmp -= max(0ll, m1 - a[i].first);
                }
            }else{
                if(a[i].first >= m1)cnt++;
            }
        }
    
        if(cnt >= m)l = m1;
        else r = m1 - 1;
    }
    res = max(res, a[n-1].first + l);
    
    cout << res << '\n';
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