#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 998244353;
const int N = 5e5 + 10;

int f[N],inv[N];

int pw(int a, int b){
  int res=1;
  while(b){
    if(b&1)res=(res*a)%M;
    b>>=1;
    a=(a*a)%M;
  }
  return res;
}

void Calc(){
  f[0]=1;
  for(int i=1; i<N; i++)f[i]=(f[i-1]*i)%M;
  inv[N-1]=pw(f[N-1],M-2);
  for(int i=N-2; i>=0; i--)inv[i]=(inv[i+1]*(i+1))%M;
}

int C(int n, int k){
    if(k > n)return 0;
    return (f[n]*inv[n-k]%M*inv[k])%M;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans+C((n/i)-1,k-1))%M;
    }
    cout<<ans%M<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
Calc();
   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

