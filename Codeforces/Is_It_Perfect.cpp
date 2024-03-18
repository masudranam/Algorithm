#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 993344777;//1e9 + 7;
const int N = 2e5 + 10;

bool isPrime(int x){
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0)return false;
    }
    return true;
}

int dp[65][1<<17][2];
int cnt[65],b[65];

int get(int i, int mask, int par){
    if(i > 60){
        if(par)return mask > 0;
        return mask == 0;
    }
    int &ret = dp[i][mask][par];
    if(ret != -1) return ret;
    ret = get(i+1,mask,par);
    if(cnt[i]){
        ret = (ret + get(i+1,mask^b[i],par^1)*cnt[i])%M;
    }
    return ret%M;
}

void solve(){

    vector<int>p;
    for(int i = 2; i <= 70; i++){
        if(isPrime(i))p.push_back(i);
    }
 
    int n;cin >> n;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
        int xx = x;
        for(int j = 0; j < sz(p) && p[j]<=x; j++){
            int cur = 0;
            while(x%p[j] == 0){
                x /= p[j];
                cur ^= 1;
            }
            if(cur)b[xx] = (b[xx] | (1<<j));
        }
    }
    memset(dp,-1,sizeof(dp));

    cout<<get(0,0,0)-1<<endl;

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

