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

int f(int x){
    return x*(x+1)/2;
}

void solve(){
    int n, k;
    cin >> n >> k;

    int ans = 0;

    for(int i = 1; i <= k; i++){
        int x = i + (k - (i%k))-1;
      
        if(x > n)continue;
        int y = 1 + (n-x)/k;
        ans += f(y);
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

