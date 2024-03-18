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
    int n, m, d;
    cin >> n >> m >> d;
    multiset<int> st;
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x >= 0)st.insert(x),cur += x;
        while(sz(st) > m)cur -= *st.begin(),st.erase(st.begin());
        ans = max(ans,cur-(i+1)*d);
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

