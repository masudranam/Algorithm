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


int pw(int a,int b){
    int res = 1;
    while(b){
        if(b&1)res = (res * a)%M;
            a = (a*a)%M;
            b >>= 1;
        
    }
    return res;
}
void solve(){
int n; cin >> n;
if(n == 1){
    cout << 8 << endl;
    return;
}
int ans = pw(9,n-1);
cout << ans*8%M << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

