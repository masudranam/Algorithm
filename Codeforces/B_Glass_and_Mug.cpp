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
    int k , g , m;
    cin >> k >> g >> m;
    
    int m1 = 0, g1 = 0;

    for(int i = 0; i <k;  i++){
        if(g1 == g)g1 = 0;
        else if(m1 == 0) m1 = m;
        else{
            int x = min(g-g1,m1);
            m1 -= x;
            g1 += x;
        }
       // cout<<g1 <<' '<<m1<<endl;
    }
    cout<<g1<<' '<<m1<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

