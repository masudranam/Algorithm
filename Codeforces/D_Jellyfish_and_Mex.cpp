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
 multiset<int> st;
 for(int i = 0; i < n; i++){
    int x; cin >> x;
    st.insert(x);
 }
 int mx = 0;
 while(st.find(mx) != st.end())mx++;
 n = mx;

 vector<int> a(n);
 for(auto x: st){
    if(x >= mx)break;
    a[x]++;
 }

 vector<int> dp(n+1);
    for(int i = n-1; i >= 0; i--){
       dp[i] = (a[i]-1)*n + i;
        for(int j = n-1; j > i; j--){
            int cur = (a[i]-1)*j + i +  dp[j];
            dp[i] = min(dp[i],cur);
        }
    }
   cout<<dp[0]<<endl;


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

