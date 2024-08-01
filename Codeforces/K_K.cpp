#include<bits/stdc++.h>
using namespace std;

#define int   long long int
const int M = 1e9 + 7;
const int N = 2e3 + 10;

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
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int cur = 1, res = 0;
        for(int i = 0; i < pfs.size(); i++){
            if(n / pfs[i] >= cur){
                res++;
                cur *= pfs[i];
            }else break;
        }
        cout << res << '\n';
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
   sieve();

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

