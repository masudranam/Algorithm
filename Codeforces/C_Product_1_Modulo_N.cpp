#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int p = 1;
    vector<int> a;
    for(int i = 1; i < n; i++){
        if(__gcd(i,n) == 1) p = (p*i) % n,a.push_back(i);
    }
    if(p == 1){
        cout << a.size() << '\n';
        print(a);
        return;
    }
    cout << a.size() - 1 << '\n';
    for(int i = 0; i < a.size(); i++){
        if(a[i] == p)continue;
        cout << a[i] <<' ';
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
