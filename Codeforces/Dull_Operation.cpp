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

bool ok(int x, int y, int n){
    int z = x^y;
    if((x^z)*(x|z) == n){
        cout<<x<<' '<<z<<endl;
        return true;
    }
    return false;
}

void solve(){
    int n;cin >> n;
    vector<int> d;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            int x = i, y = n/i;
            if(ok(x,y,n))return;
            if(ok(y,x,n))return;
        }
    }
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

