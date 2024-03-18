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
    int l, r; 
    cin >> l >> r;
    int ans = l*r;
    for(int i = 1; i * i <= r; i++){
        int x = (l+i-1)/i;
        int L = x*i, R = i*(x+1);
        if(L >= l && R <= r)ans = min(ans,i*x*(x+1));
    }

    for(int x = 1; x*x <= r; x++){
        int g = (l+x-1)/x;
        int L = x*g, R = g*(x+1);
        if(L >= l && R <= r)ans = min(ans,x*(x+1)*g);
    }
    cout<<ans<<endl;
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

