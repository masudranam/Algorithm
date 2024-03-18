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

// nC3 - > n!/((n-3)!*3!)
// n*(n-1)*(n-2)/6

int f1(int x){
    return x*(x-1)*(x-2)/6;
}

int f(int x){
    return x*(x-1)/2;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x]++;
    }
    int cur = 0, ans = 0;

    for(int i = 0; i <= n; i++){
        ans += cur*f(a[i]);
        ans += f1(a[i]);
        cur += a[i];
    }
    
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

