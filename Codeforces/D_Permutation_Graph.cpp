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

struct ST{
    int n;
    const int LOG = 22;
    vector<int> a,pw;
    vector<vector<int>>mx,mn;

    ST(vector<int> _a){
        a = _a; n = (int)a.size();  pw = vector<int>(n+10);
        mx = mn = vector<vector<int>>(n+1,vector<int>(LOG+1));

        pw[1] = 0;
        for(int i = 2; i <= n; i++){
            pw[i] = pw[i/2] + 1;
        }
        for(int i = 0; i < n; i++){
            mx[i][0] = mn[i][0] = a[i];
        }

        for(int k = 1; k < LOG; k++){
            for(int i = 0; (i+(1<<k)-1) < n; i++){
                mx[i][k] = max(mx[i][k-1],mx[i+(1<<(k-1))][k-1]);
                mn[i][k] = min(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
            }
        }
    }
    
        int qmx(int l, int r){
            int k = pw[r-l+1];
            return max(mx[l][k],mx[r-(1<<k)+1][k]);            
        }
        int qmn(int l, int r){
            int k = pw[r-l+1];
            return min(mn[l][k],mn[r-(1<<k)+1][k]);
        }
};


void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1),dp(n + 1, n),mx(n+2),mn(n+2);
    dp[1] = 0;


    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ST st(a);

    for(int i = 1; i <= n; i++){
        dp[i] = min(dp[i],dp[i-1]+1);

        int l = i, r = n, m,mx,mn;

        while(r-l > 0){  // i is mn
            m = (l+r+1)/2;
            if(st.qmn(i,m) >= a[i])l = m;
            else  r = m - 1;
        }
        if(l > i){
            mx = st.qmx(i,l);
            r = l, l = i;
            while(r-l > 0){
                m = (r+l)/2;
                if(st.qmx(i,m) >= mx)r = m;
                else l = m+1;
            }
            dp[l] = min(dp[l],dp[i]+1);
        }

        l = i, r = n;
        while(r-l > 0){ //i is mx
            m = (l+r+1)/2;
            if(st.qmx(i,m) <= a[i])l = m;
            else r = m-1;
        }

        if(l > i){
            r = l, l = i;
            mn = st.qmn(i,r);
            while(r-l > 0){
                m = (l+r)/2;
                if(st.qmn(i,m) <= mn)r = m;
                else l = m+1;
            }
            
            dp[l] = min(dp[l],dp[i]+1);
        }
       
    }

    cout << dp[n] << endl;
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

