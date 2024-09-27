#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 1e6 + 10;

struct node{
    int a, b, d;
    bool operator < (node other){
        return d > other.d;
    }
}v[N];
int n; 



void solve(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i].a >> ;
        v[i].d = v[i].b - v[i].a;
    }

}

//abacba

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

