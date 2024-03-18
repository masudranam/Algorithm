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
    int n; cin >> n;
    vector<int> a(n);

    for(auto &x: a)cin >> x;
    int mn = a[0];
    for(int i = 1; i < n; i++){
        mn = min(a[i],mn);
    }

    int ans = 1;

    for(int k = -1; k <= 1; k++){
    for(int d = 1; d*d <= mn+k; d++){
        if((mn + k)%d)continue;
        int x = d, y = (mn+k)/d;
        bool ok = 1;
        for(int i = 0; i < n; i++){
            ok &= ((a[i]-1)%x == 0 || (a[i]+1)%x == 0 || a[i]%x==0);
        }

        if(ok)ans = max(ans,x);
        ok = 1;
        x = y;
         for(int i = 0; i < n; i++){
            ok &= ((a[i]-1)%x == 0 || (a[i]+1)%x == 0 || a[i]%x==0);
        }
        if(ok)ans = max(ans,x);
    }
    }
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
    //  cout<<"Case "<<tc<<": \n";
      solve();
   }
   return 0;
}

