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

multiset<int> s[N];
map<int,int>mp[N];

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

int pw(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = (res*a)%M;
        a = (a*a) % M;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ans = __gcd(ans,x);
        while(x > 1){
            int y = lpf[x];
            int cnt = 0;
            while(x % y == 0){
                cnt++;
                x /= y;
            }
            mp[i][y] = cnt;
            s[y].insert(cnt);
        }
    }

    while(m--){
        int i, x; cin >> i >> x;
        while(x > 1){
            int y = lpf[x];
            int cnt = 0;
            while(x % y == 0)cnt++, x /= y;
            int prv = mp[i][y];
            int mn = 0;
            if(sz(s[y]) == n)mn = *(s[y].begin());
            if(prv){
                s[y].erase(s[y].find(prv));
            }
             mp[i][y] += cnt;
            s[y].insert(prv+cnt);
           
            if(sz(s[y]) == n){
                int cur = *(s[y].begin());
                ans = ans*pw(y,cur-mn)%M;
            }
        }
        cout << ans <<endl;
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

