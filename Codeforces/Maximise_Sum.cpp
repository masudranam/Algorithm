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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(auto &x: a) cin >> x;

    sort(all(a));

    for(int i = n-1; i >= 0; i--){
        if(a[i]%2 && k){
            a[i]++;
            k--;
        }
    }

    while(a[0] > 1 && k > 0){
        if(a[0]%2)a[0]++;
        else a[0]/=2;
        k--;
    }

    if(k > 0){
        k = k%2;
    }

    if(k)a[0]++;
    int ans = 0;
    for(int i = 0;i < n; i++) ans += a[i];
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

