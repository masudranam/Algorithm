#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
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
}

for(int i=0;i<=n;i++){
    int ans=0;
    for(int j=1;j<=n;j++){
        ans=max(ans,min(i,j)*x+dp[j]);
    }
    cout<<ans<<" ";
}
cout<<endl;

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

