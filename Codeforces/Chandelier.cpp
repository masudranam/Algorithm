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
    vector<int> a(n+2),b(n+2);
    for(int i = 1;  i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    vector<int> l(n+3),r(n+3);

    for(int i = n; i >= 1; i--){
        r[i] = b[i]-a[i] + max(0ll,r[i+1]-b[i]);
    }

    for(int i = 1; i <= n; i++){
        l[i] = b[i]-a[i] + max(0ll,l[i-1]-b[i]);
    }

    if(n == 1){
        cout<<b[1]-a[1]<<endl;
        return;
    }
    //l[0] = M, r[n+1] = M;
    
    for(int i = 1; i <= n; i++){
       // int y = (b[i-1]-a[i-1]) + (b[i+1]-a[i+1]) - (i>1 && i < n);
       // y = max(b[i],y);
        int y = (l[i-1]+r[i+1]);
        y = max(y,b[i]);
        cout<<y-a[i]<<" \n"[i==n];
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

