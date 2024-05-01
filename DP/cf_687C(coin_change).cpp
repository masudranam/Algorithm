//Editorials code
#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array

const int M = 1e9 + 7 ;
const int N = 500 + 10;

bool dp[2][N][N];


void solve(){
    int n,k;
    cin>>n>>k;

    dp[0][0][0]=1;
    for(int i=1; i<=n; i++){
        int cur=i%2;
        int last=cur^1;
        int x; cin>>x;
        for(int j=0; j<=k; j++){
            for(int y=0; y<=j; y++){
                dp[cur][j][y]=dp[last][j][y];
                if(j>=x){
                    dp[cur][j][y]|=dp[last][j-x][y];
                    if(y>=x)
                    dp[cur][j][y]|=dp[last][j-x][y-x];
                }
            }
        }
    }

    vector<int>res;

    for(int i=0; i<=k; i++){
        if(dp[n%2][k][i])res.push_back(i);
    }
    cout<<sz(res)<<endl;
    print(res);



}

signed main() {
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    int t = 1;   // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        //cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
