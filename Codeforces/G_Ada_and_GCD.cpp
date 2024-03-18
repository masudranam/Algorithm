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
    sieve();

    int n; cin >> n;
    vector<int> cnt(N, M), ok(N);

    for(int i = 0; i < n; i++){
        int m; cin >> m;
        map<int,int> mp;
        while(m--){
            int x; cin >> x;
            while(x > 1){
                int y = lpf[x];
                while(x%y == 0)x /= y, mp[y]++;
            }
        }
           // cout << i<<" - >"<<endl;
            for(auto it : mp){
         //   cout << it.first <<" "<<it.second<<endl;
            cnt[it.first] = min(cnt[it.first], it.second);
            ok[it.first]++;
        }
    }

    int ans = 1;
    for(int i = 2; i < N; i++){
       // cout <<i<<"->"<< ok[i] <<endl;
        if(ok[i] != n)continue;
        if(cnt[i] == M)continue;
        ans = (ans * pw(i, cnt[i])) % M;
    }

    cout << ans << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
    
   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

