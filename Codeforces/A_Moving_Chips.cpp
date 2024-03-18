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
    int n;cin >> n;
    vector<int> a(n);
    int cnt = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = n;

    for(int i = 0; i <n; i++){
        bool f = 0; cnt = 0;
        for(int j = n-1; j >= i; j--){
            if(a[j] == 0 && f)cnt++;
            f |= (a[j] == 1);
        }
        ans = min(ans, cnt);
        if(a[i] == 1)break;
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

