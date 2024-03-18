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
const int N = 2e4 + 10;

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n),p[N],vis(N);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        int x = lpf[a[i]];
        if(x <= pfs[q-1]){
            p[x].push_back(a[i]);
            vis[a[i]] = 1;
        }
    }

    vector<int> ans;
    for(int i = 0; i < q; i++){
        if(i % 2 == 0)
        for(auto x: p[pfs[i]])ans.push_back(x);
        else{
            for(int j = sz(p[pfs[i]])-1; j >= 0; j--){
                ans.push_back(p[pfs[i]][j]);
            }
        }
    }

    if(q%2 == 1){
    for(int i = 0; i < n; i++){
        if(!vis[a[i]])ans.push_back(a[i]);
    }
    }else{
        for(int i = n-1; i >= 0; i--){
            if(!vis[a[i]])ans.push_back(a[i]);
        }
    }

    for(auto x: ans)cout<<x<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
sieve();
   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

