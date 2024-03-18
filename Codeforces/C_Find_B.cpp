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
    int q; cin >> q;

    vector<int> a(n+1),c(n+1);
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        if(a[i] == 1)c[i] = 1;
        a[i] += a[i-1];
        c[i] += c[i-1];
    }

    while(q--){
        int l, r; cin >> l >> r;
        int x = a[r] - a[l-1];
        int d = r-l+1;
        int need = 2*(c[r] - c[l-1]) + (d - c[r] + c[l-1]);
        if(d > 1 && need <= x)cout <<"YES\n";
        else cout <<"NO\n";
    }

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

