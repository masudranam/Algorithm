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
const int N = 2e7 + 10;

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

int get(int x){
    int res = 0;

    for(int i = 0; pfs[i]*pfs[i] <= x && x > 1; i++){
        if(x % pfs[i] == 0){
        
            while(x % pfs[i] == 0)x/= pfs[i], res += pfs[i];
        }
    }

    if(x > 1) res += x;
    return res;
}

void solve(){
    int n; 
    while(true){
        cin >> n;
        if(n == 4)break;
    int cnt = 1;
 
    while(n > 1){
        int y = get(n);
        if(y == n){
            cout <<y <<' ' << cnt << endl;
            break;
        }
        cnt++;
        n = y;
    }

 

    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
sieve();
   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

