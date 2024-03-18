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
int x = abs(n - 50);

if(n == 50){
    cout <<0 << endl;
    return;
}
if(n > 50){
    if(x % 3 == 0)cout << x/3 << endl;
    else if(x % 3 == 1)cout << x/3 + 2 << endl;
    else cout << x/3 + 4 << endl;
}else{
    if(x%2 == 0)cout << x/2 << endl;
    else cout << x/2 + 3 << endl;
}
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

