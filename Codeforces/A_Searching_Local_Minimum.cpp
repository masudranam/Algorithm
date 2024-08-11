#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

pair<int,int> get(int i){
    cout <<"? "<< i << endl;
    int x; cin >> x;
    cout <<"? "<< i + 1 << endl;
    int y; cin >> y;
    return {x, y};
}

void solve(){
    int n; cin >> n;
    int l = 1, r = n;

    while(l < r){
        int m = (l + r) / 2;
        pair<int,int> p = get(m);
        if(p.first < p.second) r = m;
        else l = m + 1;
    }
    cout <<"! "<< l << endl;
}

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