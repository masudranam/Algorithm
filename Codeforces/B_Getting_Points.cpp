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
    int n, p, l, t;
    cin >> n >> p >> l >> t;

    int task = ((n-1)/7) + 1;

    int left = 0, right = n;
   
    while(right-left > 0){
        int m = (left+right)/2;

        int tot = min(2*m,task)*t + l*m;
        if(tot >= p) right = m;
        else left = m+1;      
    }
    //left--;
    //debug(left);
   // debug(min(left,task)*t + l*left);
    cout<<n-right<<endl;
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

