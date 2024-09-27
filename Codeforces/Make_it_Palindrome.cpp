#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];
int get(int x, int l, int r){
    return upper_bound(g[x].begin(), g[x].end(), r) - lower_bound(g[x].begin(), g[x].end(), l);
}

 
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
        g[x].push_back(i);
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(n - i - 1 < i){
        int l = n - i - 1;
        res += (i - l - get(a[i], l, i - 1)) * (n - i);
        }
        if(n - i - 2 > i){
            int r = n - i - 2;
            res += (r - i - get(a[i], i + 1, r)) * (i + 1);
        }
    }
    cout << res << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
