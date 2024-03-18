#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M =998244353 ;
const int N = 2e5 + 10;

int f(int l, int r){
    return ((r+l)*(r-l+1))/2;
}

int f(int i, int l, int r){
    int res = f(l,r) % M;
    return (i*res) % M;
}

void solve(){
    int n, m;cin >> n >> m;
    if(n < m)swap(n, m);
    
    int i = (n+1)/2;
    int l = i, r = m - l+1;

    int ans = f(i,l,r) % M;
    if(n%2 == 0) ans = (ans + f(i+1,l,r)) % M;
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

