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
const int N = 1e7 + 10;

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
    int n; cin >> n;
    map<int,int>mp;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        int cur = 1;
        while(x > 1){
            int y = lpf[x];
            while(x%(y*y) == 0) x /= (y*y);
            if(x%y == 0)cur = cur*y, x/=y;
        }
        if(cur > 1)mp[cur]++;
        
    }

    int ans = 0;
    for(auto it: mp){
        ans = max(ans,it.second);
    }
    cout<<ans<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
sieve();
   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

