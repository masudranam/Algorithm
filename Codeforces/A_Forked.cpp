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

struct ST{
    int n;
    const int LOG = 22;
    vector<int> a,pw;
    vector<vector<int>>mx,mn;

    ST(vector<int> _a){
        a = _a; n = (int)a.size();  pw = vector<int>(n+10);
        mx = mn = vector<vector<int>>(n+1,vector<int>(LOG+1));

        pw[1] = 0;
        for(int i = 2; i <= n; i++){
            pw[i] = pw[i/2] + 1;
        }
        for(int i = 0; i < n; i++){
            mx[i][0] = mn[i][0] = a[i];
        }

        for(int k = 1; k < LOG; k++){
            for(int i = 0; (i+(1<<k)-1) < n; i++){
                mx[i][k] = max(mx[i][k-1],mx[i+(1<<(k-1))][k-1]);
                mn[i][k] = min(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
            }
        }
    }
    
        int qmx(int l, int r){
            int k = pw[r-l+1];
            return max(mx[l][k],mx[r-(1<<k)+1][k]);            
        }
        int qmn(int l, int r){
            int k = pw[r-l+1];
            return min(mn[l][k],mn[r-(1<<k)+1][k]);
        }
};


void solve(){
    int n; cin >> n;
    vector<int> a(n),b(n),id[n+1];
 
    for(int i = 0; i < n; i++){
        cin >> a[i];
        id[a[i]].push_back(i);
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    ST sa(a),sb(b);
 
    for(int i = 0; i < n; i++){
        auto it = lower_bound(all(id[b[i]]),i);
 
        if(it != id[b[i]].end()){
            int x = *it;
            if(sa.qmx(i,x) <= b[i] && sb.qmn(i,x) >= b[i])continue;
        }
        if(it != id[b[i]].begin()){
            it--;  int x = *it;
            if(sa.qmx(x,i) <=  b[i] && sb.qmn(x,i) >= b[i])continue;
        }
        cout<<"NO\n";return;
    }
 
    cout<<"YES\n";
    
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

