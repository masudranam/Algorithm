#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m;
    cin >> n >> m;
    int l = n + 1 + m;
    vector<int> a(l),b(l);

    int as = 0, bs = 0;
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    vector<int> vis(l);
    
    for(int i = 0, p = 0, q = 0; i < l; i++){
        if(a[i] > b[i]){
            if(p <= n){
                p++;
                as += a[i];
                vis[i] = 1;
            }else{
                as += b[i];
            }
        }else{
            if(q < m){
                as += b[i];
                q++;
            }else{
                as += a[i];
                vis[i] = 1;
                p++;
            }
        }
    }

    for(int i = 0, p = 0, q = 0; i < l; i++){
        if(a[i] < b[i]){
            if(q <= m){
                q++;
                bs += b[i];
            }else{
                bs += a[i];
            }
        }else{
            if(p < n){
                bs += a[i];
                p++;
            }else{
                bs += b[i];
                q++;
            }
        }
    }

    vector<int> res(l);

    for(int i = 0; i < l; i++){
        if(vis[i]){
            res[i] = as - a[i];
        }else{
            res[i] = bs - b[i];
        }
    }

    print(res);
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
