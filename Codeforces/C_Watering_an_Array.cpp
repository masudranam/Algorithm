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
    int k; cin >> k;
    int d; cin >> d;

    vector<int> a(n+1);

    for(int i = 0; i < n ; i++)cin >> a[i];

    vector<int> b(k);
    for(int i = 0; i < k; i++) cin >> b[i];


    int ans = 0;

    for(int i = 0; i < min(2*n,d); i++){
        int cnt = 0;
        for(int j = 0; j < n; j++)cnt += (a[j] == j+1);
        ans = max(ans,cnt + ((d-i-1)/2));
        for(int j = 0; j < b[i%k]; j++)a[j]++;                
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