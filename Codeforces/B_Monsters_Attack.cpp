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
    int k; cin >> k;
    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<int> c(n+1);

    for(int i = 0; i < n; i++){
        if(b[i] < 0)b[i] = -b[i];
        c[b[i]] += a[i];
    }

    for(int i = 1, cur = 0; i <= n; i++){
        cur += k;
       // cout << cur <<' '<<c[i]<<endl;
        if(c[i] > cur){
            cout <<"NO\n";return;
        }
        cur -= c[i];
    }
    cout <<"YES\n";
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

