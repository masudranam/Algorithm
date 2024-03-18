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
    vector<string> v(k);
    string s; cin >> s;
    for(int i = 0;i < k; i++){
        for(int j = i; j < n; j += k){
            v[i] += s[j];
        }
    }

    int ans = 0;
    bool ok = 1;

    for(int i = 0;i < k; i++){
        int one = count(all(v[i]),'1');
        ans += (one/2 + 2*(one%2));
        if(one == 0)ok = 0;
    }

    if(ok){
        int cur = 0;
        for(int i = 0; i < k; i++){
            int one = count(all(v[i]),'0');
            cur += one;
        }
        ans = min(ans,cur);
    }
    cout<<ans<<endl;

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

