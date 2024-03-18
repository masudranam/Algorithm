
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

struct Combi{
    int n; vector<int> f, finv, inv;
    int pw(int a, int b){
        int res = 1;
        while(b){
            if(b&1)res = (res*a)%M;
            a = (a*a) % M;
            b >>= 1;
        }
        return res;
    }

   Combi(int _n): n(_n), f(_n), finv(_n), inv(_n){
    inv[1] = f[0] = finv[0] =  1;
    for(int i = 2; i < n; i++) inv[i] =  (inv[M % i] * (-M / i) % M + M) % M;
    for(int i = 1; i < n; i++) f[i] = (f[i - 1] * i)%M;
    for(int i = 1; i < n; i++) finv[i] = (finv[i-1]*inv[i])%M;

   //finv[n-1] = pw(f[n-1],M-2);
   //for(int i = n-2; i >= 0; i--){
   // finv[i] = (finv[i + 1] * (i+1))%M;
   //}

  }
  inline int ncr(int n, int r) { return n<r?0:(f[n]*finv[r]%M*finv[n-r])%M;}
  inline int npr(int n, int r) {return n<r?0:(f[n]*finv[n-r]%M);}
};

int lpf[N];
vector<int>pfs;
void sieve() {
    for(int i=2; i<N; i++) {
        if(!lpf[i]) {
            pfs.push_back(i);
            lpf[i]=i;
        }
        for(int j=0; j<pfs.size() && pfs[j]<=lpf[i]&& i*pfs[j]<N; j++) {
            lpf[i*pfs[j]]=pfs[j];
        }
    }
}

Combi C(N);
void solve(){
    
    int n, m;
    cin >> n >> m;

    int two = 0, three = 0, four = 0;

    for(int i = 0; pfs[i] <= n; i++){
        two += (n-pfs[i]);
        two %= M;
    }

    for(int i = 1; pfs[i] < n; i++){
        if(pfs[i]-pfs[i-1] == 2){
            three += (n-pfs[i]);
            three%=M;
        }
    }

    four = max(0ll,n-7);
    int ans = n;
    ans = (ans + two*C.ncr(m-1,1))%M;
    ans = (ans + three*C.ncr(m-1,2))%M;
    ans = (ans + four*C.ncr(m-1,3))%M;
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

sieve();
   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

