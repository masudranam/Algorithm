#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
// #define int   long long int

const int M = 1e9 + 7;
const int N = 5e7 + 10;

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

void solve(){
    

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
   
   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

