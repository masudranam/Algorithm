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
int l, r; cin >> l >> r;

for(int i = l,cnt = 100; i <= r && cnt--; i++){
    if(i%2 == 0 && i > 3){
        cout<<2<<' '<<i-2<<endl;
        return;
    }
    for(int j = 2; j <= 10000; j++){
        int x = j, y = i-j;
        if(y >=2  && __gcd(x,y)!= 1 && (x+y)>= l && (x+y)<=r){
            cout<<x<<' '<<y<<endl;return;
        }
    }
}
cout<<-1<<endl;



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

