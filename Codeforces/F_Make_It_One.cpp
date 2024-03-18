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
const int N = 3e5 + 10;

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

    map<int,int> mp;
    for(int i = 0; i < sz(pfs); i++){
        mp[pfs[i]] = i;
    }   

    vector<int> a(n);

    bool ok = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 1)ok = 1;
        int cur = 0;

        while(x > 1){
            int y = lpf[x];
            while(x % y == 0) x/= y;
            y = mp[y];
            cur |= (1 << y);
        }
        a[i] = cur;
    }

    if(ok){
        cout<<1<<endl;return;
    }    

    set<int> st;
    map<int,int> dp;
    dp[0] = n+1;

    for(int i = 0; i < n; i++){
        set<int> nst;
        dp[a[i]] = 1;
        nst.insert(a[i]);
  
        for(auto x: st){
            if(dp.find(x&a[i]) == dp.end()){
                dp[x&a[i]] = dp[x]+1;
            }else dp[x&a[i]] = min(dp[x&a[i]],dp[x]+1);
            nst.insert(x&a[i]);
        }
        st = nst;
    }

    if(dp[0] > n)cout<<-1<<endl;
    else cout<< dp[0] << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
    sieve();
   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

