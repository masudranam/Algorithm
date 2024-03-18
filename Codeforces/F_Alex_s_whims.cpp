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
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i < n; i++){
        cout<<i<<' '<<i+1<<endl;
    }
    int last = n-1;

    for(int i = 1; i <= q; i++){
        int d; cin >> d;
        if(d == last){
            cout<<-1<<' '<<-1<<' '<<-1<<endl;
            continue;
        }
        cout<<n<<' '<<last<<' '<<d<<endl;
        last = d;
    }
    
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

