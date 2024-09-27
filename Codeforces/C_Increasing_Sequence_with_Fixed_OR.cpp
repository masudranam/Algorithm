#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < 63; i++){
        if((n>>i)&1)a.push_back(i);
    }
    if(a.size() == 1){
        cout << 1 << '\n';
        cout << n << '\n';
        return;
    }
    cout << a.size() + 1 << '\n';

    cout << (1ll << a[a.size()-2]) << ' ';

    for(int i = a.size() - 2; i >= 0; i--){
        int x = n - (1ll << a[i]);
        cout << x <<' ';
    }
    cout << n << '\n';
    
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