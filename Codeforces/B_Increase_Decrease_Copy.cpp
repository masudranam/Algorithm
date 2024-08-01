#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve1(){
    int n; cin >> n;
    vector<int> a(n),b(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i <= n; i++){
        cin >> b[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(a[i] - b[i]);
    }
    ans++;

    for(int i = 0; i < n; i++){
        if(b[n] >= min(a[i],b[i]) && b[n] <= max(a[i],b[i])){
            cout << ans << '\n';
            return;
        }
    }
    int mn = 2*M;
    for(int i = 0; i < n; i++){
        mn = min(abs(b[i] - b[n]), mn);
        mn = min(abs(a[i] - b[n]), mn);
    }
    cout << ans + mn << '\n';
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

