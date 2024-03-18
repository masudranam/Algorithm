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
vector<int> d[N], f(N,0),cnt(N);

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < N; i++)f[i] = 0;

    for(auto &x: a)cin >> x;
    sort(all(a));

    int ans = 0;

    for(int i = 0; i< n; i++){
        for(auto x: d[a[i]])cnt[x] = 0;

        for(auto x: d[a[i]]){
           int z = f[x]-cnt[x];
            ans += x*z*(n-i-1);
           for(auto y: d[x]){
            if(y == x)continue;
            cnt[y] += z;
           }
        }
        for(auto x: d[a[i]])f[x]++;
    }

    cout<<ans<<endl;
    
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
 for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            d[j].push_back(i);
        }
    }
    
    for(int i = 0; i < N; i++){
        reverse(all(d[i]));
    }
   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

