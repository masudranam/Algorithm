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
    string s; cin >> s;
    int cnt = count(all(s),'1');
    int ans = cnt;

    for(int i = 0; i < k; i++){
        int d = 0;
        for(int j = i; j < n; j += k){
            if(s[j] == '1')d++;
            else d--;
            d = max(0ll,d);
            ans = min(ans,cnt-d);
        }
    }
    
    cout << ans << endl;

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

