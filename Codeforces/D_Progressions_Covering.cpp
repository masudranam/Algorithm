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
    vector<int> a(n+1),s(n+1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    int ans = 0,cnt = 0, cur = 0;

    for(int i = n; i >= 1; i--){
        if(a[i] > cur){
            int len = min(i,k);
            int x = (a[i] - cur + len-1) / len;
            cur += x*len;
            cnt += x;
            ans += x;
            s[max(i-len+1,1ll)] -= x;
        }
        
        cur -= cnt;
        cnt += s[i];
    }

    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

