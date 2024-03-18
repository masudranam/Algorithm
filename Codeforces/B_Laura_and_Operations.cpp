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

int f(int a, int b, int c){
    if(b%2 != c%2)return 0;
    a += min(b,c);
    b = abs(b-c);
    
    if(b%2 == 0){
        if(a)return 1;
        else 0;
    }else{
        if(a > 1)return 1;
        else return 0;
    }
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    
    cout<<f(a,b,c)<<' '<<f(b,a,c)<<' '<<f(c,a,b)<<endl;


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

