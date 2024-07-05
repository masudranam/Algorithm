#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n+2), b(n+2),c(n+2),p(n+2),s(n+2);
    p[0] = 1, s[n+1] = 1;
    bool ok = 1;
    a[0] = 1;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = __gcd(a[i-1],a[i]);
        ok &= (b[i] >= b[i-1]);
        if(b[i] >= b[i-1] && p[i-1])p[i] = 1;
    }

    if(ok){
        cout << "YES\n";
        return;
    }
    c[n+1] = M;

    for(int i = n; i >= 1; i--){
        c[i] = __gcd(a[i],a[i+1]);
        if(c[i] <= c[i+1] && s[i+1]){
            s[i] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        int g = __gcd(a[i-1],a[i+1]);
        if(g >= b[i-1] && g <= c[i+1] && p[i-1] && s[i+1]){
            cout << "YES\n";return;
        }
    }

    //print(p);print(s);
   // print(b);print(c);

    cout << "NO\n";

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
