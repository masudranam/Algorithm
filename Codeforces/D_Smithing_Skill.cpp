#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 1e6 + 10;

void solve(){
    int n; cin >> n;
    int m; cin >> m;
    
    vector<pair<int,int>> a(n);
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].second;
        s = max(s, a[i].second);
    }
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].first = a[i].second - a[i].first;
    }
    
    sort(a.begin(),a.end());

    vector<int>f(N+1,M);
    for(auto it : a){
        f[it.second] = min(f[it.second],it.first);
    }
    for(int i = 1; i < N; i++){
        f[i] = min(f[i],f[i-1]);
    }

    int ans = 0;
    vector<int> cnt(N);

    for(int i = 0; i < m; i++){
        int c; cin >> c;

        if(c >= s){
            ans += (c - s) / f[s];
            ans++;
            c = (c - s) % f[s] + s - f[s];
        }
        cnt[c]++;
    }

    for(int i = s; i >= 1; i--){
        int x = cnt[i];
        if(!x)continue;
        if(f[i] <= i){
           ans += x; 
           cnt[i - f[i]] += x; 
        }
    }


    cout << 2*ans << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

