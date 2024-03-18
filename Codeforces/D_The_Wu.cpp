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
const int N = 4090 + 10;

int n, m, q;
int cnt[N],dp[N][110],w[12];

int bin(string &s){
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1')cur += (1<<(n-i-1));
    }
    return cur;
}

int wu(int s, int t){
    int res = 0;
    for(int i = 0; i < n; i++){
        int sp = s & (1<<(n-i-1));
        int tp = t & (1<<(n-i-1));
        if(sp == tp)res += w[i];
    }
    return res;
}

void solve(){
    
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++){
        cin >> w[i];
    }

    for(int i = 0; i < m; i++){
        string s; cin >> s;
        cnt[bin(s)]++;
    }

    memset(dp,-1,sizeof(dp));

    while(q--){
        string s; cin >> s;
        int k; cin >> k;
        int x = bin(s);
        if(dp[x][k] != -1){
            cout<<dp[x][k]<<endl;
            continue;
        }

        for(int i = 0; i < (1<<n); i++){
            int val = wu(i,x);
            if(val <= 101){
                dp[x][val] = max(dp[x][val]+cnt[i],cnt[i]);
            } 
        }
        int val = 0;
        for(int i = 0; i <= 101; i++){
            val += max(0ll,dp[x][i]);
            dp[x][i] = val;
        }
        cout<<dp[x][k]<<endl;
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

