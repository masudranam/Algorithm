#include <bits/stdc++.h>
using namespace std;
#define  ar        array
#define int        long long
#define all(x)     (x).begin(),(x).end()
#define debug(x)   cout<<#x<<" "<<x<<endl;
#define print(v)   for(auto x: v)cout<<x<<" ";
#define fast       ios_base::sync_with_stdio(false);cin.tie(NULL);

const int M=1e9+7;
const int N=5e5+100;


void solve(){
int n,x;cin>>n>>x;
vector<int> dp(n+5,0),a(n+1);

for(int i=1;i<=n;i++){
    cin>>a[i];
    a[i]+=a[i-1];
}
for(int i=1;i<=n;i++){
    dp[i]=-M;
    for(int j=i;j<=n;j++)
    dp[i]=max(dp[i],a[j]-a[j-i]);
   // cout<<dp[i]<<" ";
}

for(int i=0;i<=n;i++){
    int ans=0;
    for(int j=1;j<=n;j++){
        ans=max(ans,i*x+dp[j]);
    }
    cout<<ans<<" ";
}
cout<<endl;

}

signed main() {fast;
int t=1; cin>>t;
while(t--)solve();
return 0;}

 