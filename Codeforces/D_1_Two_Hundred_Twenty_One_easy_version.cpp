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
    int n, q; cin >> n >> q;
    string s; cin >> s;

    int sign[] = {1,-1};

    vector<int> ps(n+1),ms(n+1);
    for(int i = 0; i < n; i++){
        if(s[i] == '+') ps[i+1] = (ps[i] + sign[i%2]*1);
        else ps[i+1] = (ps[i] + sign[i%2]*(-1));
    }
     print(ps); 
    while(q--){
        int l, r; cin >> l >> r;l--;
        // int tot = abs(ps[r]-ps[l]) + abs(ms[r] - ms[l]);
        cout<<abs(ps[r]-ps[l])<<endl;
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

