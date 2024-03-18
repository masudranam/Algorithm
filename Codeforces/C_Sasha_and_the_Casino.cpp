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
    int k, x, a;
    cin >> k >> x >> a;

    int loss = 0;
    bool f = 1;
    for(int i = 0; i <= x; i++){
        int l = 1, r = loss+1;
        while(r-l > 0){
            int m = (l+r)/2;
            if(loss + m < m*k)r = m;
            else l = m+1;
        }
        f &= ((loss + r) <= a);
        loss += r;
    }
    if(f) cout <<"YES\n";
    else cout <<"NO\n";
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

