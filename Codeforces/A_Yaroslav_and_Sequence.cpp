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
    vector<int> a(2*n-1);
    int k = 0;
    for(int i = 0; i < 2*n-1; i++){
        cin >> a[i];
        if(a[i] < 0)k++,a[i] = abs(a[i]);
    }
    
    if(k == n || k%2 == 0 || n%2)k = 0;
    k = k%2;
    
    int sum = 0;
    sort(all(a));
    for(int i = 0; i < 2*n-1; i++){
        if(i < k)sum -= a[i];
        else sum += a[i];
    }
    cout<<sum<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

