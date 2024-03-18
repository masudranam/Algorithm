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
    int n, K = 0;
    cin >> n;

    vector<int> a(n),ps(2*n+2),ans(n);

    for(int i = 0; i < n; i++){
        cin >> a[i]; 
        K += a[i];
    }
 
    K /= n;

    if(a[n-1] == n && K){
        ans[n-1] = 1;
         K--;
         ps[n-1] = 1;
    }

    for(int i = n-2; i >= 0 && K > 0; i--){
        ps[i] += ps[i+1];
        
        if(a[i] < i){
            continue;
        }
        int x = ps[i] - ps[a[i]+1] + K;
        if(a[i] - i == x || a[i] == n){
            ps[i]++;
            ans[i] = 1;
            K--;
        }
    }

    print(ans);

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

