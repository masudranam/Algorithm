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
    int m; cin >> m;
    vector<int> a(n), b(m);

    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    sort(all(a));
    sort(all(b));
    reverse(all(b));

    int ai = 0, aj = n-1, bi = 0, bj = m-1;
    int ans = 0;

    while(ai <= aj){
        int x = abs(a[ai] - b[bi]);
        int y = abs(a[aj] - b[bj]);
        if(x > y)ans += x, ai++,bi++;
        else ans += y, aj--,bj--;
    }

    cout << ans << endl;
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

