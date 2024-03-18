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
const int N = 1e6 + 10;

int a[N],n;

int get(int k){
    int cur = 0, ans = 0;
    for(int i = 0; i < n; i++){
        cur += a[i];
       // cout<<cur<<' '<<min(cur%k,k-cur%k)<<endl;
        ans += min(cur%k,k-cur%k);
    }
    return ans;
}

void solve(){
    cin >> n;
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i], s += a[i];
    }

    if(s <= 1){
        cout<<-1<<endl;
        return;
    }
    int ans = M*M;

    for(int i = 2; i*i <= s; i++){
        if(s%i == 0){
            while(s % i == 0) s /= i;
            ans = min(ans,get(i));
        }
    }
    if(s > 1)ans = min(ans,get(s));
    cout<<ans<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

