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


int ps[N],vis[N],p[N];
int n, k;

bool ok(int x){
    for(int i = 0; i <= n; i++)vis[i] = 0,p[i] = 0;
    vis[0] = 1;
    p[0] = 1;

    for(int i = 1; i <= n; i++){
        p[i] += p[i-1];
        if(i < k)continue;
        auto it = lower_bound(ps+1,ps+n+1,ps[i]-x)-ps;
        if(it+k-1 > i)continue;
        it--;
        if(p[i-k]-(it?p[it-1]:0) >= 1){
            p[i]++;
        }
    }
    return (p[n]-p[n-1] >= 1);
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <=n; i++){
        cin >> ps[i];
    }
    sort(ps+1, ps + n + 1);
    
    int l = 0, r = M;
    while(r - l > 0){
        int m = (l+r)/2;
        if(ok(m))r = m;
        else l = m + 1;
    }

    cout << l << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}