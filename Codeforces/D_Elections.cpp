#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    a[0] += c;

    vector<int> b(n),m(n+1);
    int mx = 0;
    for(int i = 0; i < n; i++){
        b[i] = a[i];
        mx = max(mx, a[i]);
        if(i) b[i] += b[i-1];
    }
    for(int i = n-1; i >= 0; i--){
        m[i] = max(m[i+1],a[i]);
    }
    int tmx = a[0];
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(mx > a[i])cout << 1 <<' ';
            else cout << 0 <<' ';
            continue;
        }
        if(tmx < a[i] && a[i] >= mx){
            cout << 0 <<' ';
            tmx = a[i];
            continue;
        }
        tmx = max(tmx,a[i]);
        if(b[i-1] + a[i] >= mx){
            cout << i <<' ';continue;
        }
        cout << i + 1 <<' ';
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

