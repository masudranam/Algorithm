#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 3e5 + 10;

int a[N], s[N];
int n;

bool ok(int x, int t){
    auto i = lower_bound(a + 1, a + n + 1, x) - a;
    return (n - i + 1) * x + s[i-1] >= t;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x]++;
    }
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + a[i];
    }
    
    for(int i = 1; i <= n; i++){
        int l = 0, r = n;
        while(r - l > 0){
            int m = (l + r + 1) / 2;
            if(ok(m,i*m))l = m;
            else r = m - 1;
        }
        cout << l << '\n';
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
