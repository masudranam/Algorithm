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
    int n; cin >> n;
    int a[n+2],s[n+2],p[n+2];

    s[0] = 0, p[n+1] = 0;
    a[0] = a[n+1] = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i]; 
        s[i] = (s[i-1]+abs(a[i-1]-a[i]));
    }

    for(int i = n; i >= 1; i--){
        p[i] = (p[i+1] + abs(a[i+1]-a[i]));
    }
    for(int i = 1; i <= n; i++){
        cout<<s[i-1]+p[i+1]+abs(a[i-1]-a[i+1])<<endl;
    }
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

