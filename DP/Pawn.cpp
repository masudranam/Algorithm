#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 100 + 10;

int a[N][N];
string s[N];
int dp[N][N][12];
int n, m, K;

int get(int i, int j, int k){
    if(i == n){
        if(k == 0)return 0;
        return -M;
    }

    int &ret = dp[i][j][k];
    if(ret != -1) return ret;

    ret = -M;
    if(j){
        ret = max(ret, a[i][j-1] + get(i+1,j-1,(k+a[i][j-1])%K));
    }
    if(j + 1 < m){
        ret = max(ret, a[i][j+1] + get(i+1,j+1,(k+a[i][j+1])%K));
    }
    return ret;
}

void P(int i, int j, int k){
    if(i == n)return;
    int &ret = dp[i][j][k];
    if(j && (a[i][j-1] + get(i+1,j-1,(k+a[i][j-1])%K)) == ret){
        cout<<"L";
        P(i+1,j-1,(a[i][j-1]+k)%K);
    }else{
        cout<<"R";
        P(i+1,j+1,(k+a[i][j+1])%K);
    }
}


void solve(){
    cin >> n >> m >> K, K++;

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n/2; i++){
        swap(s[i],s[n-i-1]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = s[i][j]-'0';
        }
    }

    memset(dp,-1,sizeof(dp));
    int ans = -M, id;

    for(int i = 0;i < m; i++){
        if(a[0][i] + get(1,i,a[0][i]%K) > ans){
            id = i;
            ans = a[0][i] + get(1,i,a[0][i]%K);
        }
    }

    if(ans < 0){
        cout<<-1<<endl;
        return;
    }
    
    cout<<ans<<endl;
    cout<<id+1<<endl;

    P(1,id,(a[0][id]%K));
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

