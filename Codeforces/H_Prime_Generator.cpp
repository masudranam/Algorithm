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

int lpf[N];
vector<int>pfs;
vector<int> sieve() {
    for(int i=2; i<N; i++) {
        if(!lpf[i]) {
            pfs.push_back(i);
            lpf[i]=i;
        }
        for(int j=0; j<pfs.size() && pfs[j]<=lpf[i]&& i*pfs[j]<N; j++)
            lpf[i*pfs[j]]=pfs[j];
    }
    return pfs;
}


vector<int> segSieve(int l,int r) {
    bool isPrime[r-l+1];
    vector<int>prime=sieve(),p;
    for(auto &a:isPrime)a=true;


    for(int i=0; prime[i]*prime[i]<=r; i++) {
        int cp=prime[i];
        int base=(l/cp)*cp;
        if(base<cp)base+=cp;
        for(int j=base; j<=r; j+=cp)
            isPrime[j-l]=false;
        if(base==cp)isPrime[base-l]=true;
    }
    for(int i=0; i<r-l+1; i++) {
        if(isPrime[i]==true)p.push_back(i+l);
    }
    return p;
}


void solve(){
    int l, r;
    cin >> l >> r;
    vector<int> p = segSieve(l,r);
    for(auto x : p){
        if(x == 1)continue;
        cout << x << endl;
    }
    cout << endl;
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

