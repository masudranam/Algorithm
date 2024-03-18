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
    int x,y,n;
    cin >> x >> y >> n;
    vector<int> a(n+1);
    a[n] = y;
    int cur = 1;
    for(int i = n-1; i >= 1; i--){
        a[i] = a[i+1]-cur;
        cur++;
    }
    if(a[1] < x){
        cout<<-1<<endl;
    }else {
        a[1] = x;
        for(int i = 1; i <= n; i++)cout<<a[i]<<' ';
        cout<<endl;
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

