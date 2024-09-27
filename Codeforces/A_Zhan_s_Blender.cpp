#include<bits/stdc++.h>
using namespace std;


#define int   long long int
 

const int N = 2e5 + 10;

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t; cin >> t;
   while(t--){
      int n; cin >> n;
      int a, b; cin >> a >> b;
      cout << max((a + n - 1) / a, (n + b - 1) / b) << '\n';
   }
   return 0;
}