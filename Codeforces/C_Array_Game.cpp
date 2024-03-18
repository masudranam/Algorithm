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

    if(k >= 3){
        cout<<0<<endl;
        return;
    }

    sort(all(a));
    int ans = abs(a[1]-a[0]);
    for(auto x: a)ans = min(ans,x);
    
    if(k == 1){
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ans = min(ans,abs(a[i]-a[j]));
            }
        }
    }

    if(k == 2){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){

            ans = min(ans,abs(a[i]-a[j]));
            int x = abs(a[j]-a[i]);
            auto it = lower_bound(all(a),x)-a.begin();
            if(it != n){
                ans = min(abs(x-a[it]),ans);
            }

            if(it != 0){
                ans = min(ans, abs(x-a[it-1]));
            }
        }
    }
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