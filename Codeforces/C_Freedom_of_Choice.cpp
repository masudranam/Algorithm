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

void solve(){
    int m;
    cin >> m;

    map<int,int> Global,Local,extra;
    set<int> st;

    int total = 0, mn = 0, mx = 0;

    for(int j = 0; j < m; j++){
        int n, l, r; cin >> n >> l >> r;
        total += r;
        mn += l, mx += r;

        vector<int> a(n),c(n);
        int cur = 0;

        for(auto &x: a) cin >> x;
        for(auto &x: c) cin >> x, cur += x;

        for(int i  = 0; i < n; i++){
            Local[a[i]] += r;
            int ache = cur - c[i];
            extra[a[i]] += max(0ll,l-ache);
            ache = max(ache,l);
            Global[a[i]] += min(r,ache);
            st.insert(a[i]);
        }
    }   
    //debug(mn);debug(mx);
   
    for(int i = mn; i <= mx; i++){
        if(st.find(i) == st.end()){
            cout<<0<<endl;return;
        }
    }

    int ans = M*M;

    for(auto x: st){
        if(x < mn || x > mx)continue;
        int ache = (total-Local[x]) + (Global[x]);
        ans = min(ans,max(0ll,x-ache) + extra[x]);
    }

    cout << ans << endl;

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

