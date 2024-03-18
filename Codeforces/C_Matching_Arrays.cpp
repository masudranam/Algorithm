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
    int n, x;
    cin >> n >> x;

    vector<ar<int,2>> a;
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back({x,i});
    }
    for(int &x: b) cin >> x;

sort(all(a)); sort(all(b));

    int l = 0, r = n - x;

    while(r-l > 0){
        int m = (l+r+1)/2;
        bool ok = 1;
        int id = 0;

        for(int i = m; i < m+x; i++){
            ok &= (a[i][0] > b[id++]);
        }
        if(ok)l = m;
        else r = m-1;
    }

    vector<int> ans(n);

    bool ok = 1;
    int id = 0;


    for(int i = l; i < n,l+x; i++){
        ok &= (a[i][0] > b[id]);
        ans[a[i][1]] = b[id++];
    }

    for(int i = 0; i< l; i++){
        ok &= (a[i][0] <= b[id]);
        ans[a[i][1]] = b[id++];
    }
   
    for(int i = l+x; i < n; i++){
        ok &= (a[i][0] <= b[id]);
        ans[a[i][1]] = b[id++];
    }
    if(!ok){
        cout<<"NO\n";return;
    }
    cout<<"YES\n";

    for(int i = 0; i < n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    
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

