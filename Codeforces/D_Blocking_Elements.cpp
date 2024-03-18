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

int a[N], b[N];
int n;

int ok(int x){
    multiset<pair<int,int>> st;
    st.insert({0,0});
    vector<int> dp(n+1,N*M);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        while(sz(st)){
            pair<int,int> p = *st.begin();
            int y = max(0ll,b[i-1] - b[p.second]);
            if(y <= x){
                dp[i] = min(dp[i], p.first + a[i]);
                break;
            }else{
                st.erase(st.begin());
            }
        }
        st.insert({dp[i],i});
    }
    int cur = 0;
    for(int i = n; i >= 1; i--){
        //cout << i<<' '<<dp[i]<<endl;
        if(dp[i] <= x && cur <= x)return true;
        cur += a[i];
    }
    return false;
}

void solve(){
   cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    int l = 0, r = N*M;
    while(r - l > 0){
        int m = (l+r)/2;
        if(ok(m)) r = m;
        else l = m+1;
    }
    cout << l << endl;
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

