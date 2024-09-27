#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    int sum = 0, res = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        if(a[i] == 1 && a[i - 1] > 1){
            cout << - 1 << '\n';return;
        }
        double tmp = log2((log2(a[i-1]) / log2(a[i])));
        tmp = ceil(tmp);
        
        sum = max(sum + (int)tmp, 0ll);
        res += sum;
    }
    cout << res << '\n';


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