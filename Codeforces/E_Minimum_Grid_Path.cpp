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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int oddCnt = 1, evenCnt = 1, oddSum = a[0], evenSum = a[1];
    int oddMin = a[0], evenMin = a[1];

    int ans = n*oddMin + n*evenMin;

    for(int i = 2; i < n; i++){
        if(i&1){
            evenCnt++;
            evenSum += a[i];
            evenMin = min(evenMin, a[i]);
        }else{
            oddCnt++;
            oddSum += a[i];
            oddMin = min(oddMin, a[i]);
        }
        int x = (n-evenCnt+1)*evenMin + (evenSum-evenMin);
        int y = (n-oddCnt+1)*oddMin + (oddSum-oddMin);
        ans = min(ans, x + y);
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

