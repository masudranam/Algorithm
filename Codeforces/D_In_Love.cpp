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
    int n; cin >> n;
    multiset<int> sl,sr;

    for(int i = 0; i < n; i++){
        char c ; cin >>c;
        int l, r; cin >> l >> r;
        if(c == '+')sl.insert(l),sr.insert(r);
        else {
            sl.erase(sl.find(l));
            sr.erase(sr.find(r));
        }
        auto it = sl.upper_bound(*sr.begin());
        if(it == sl.end())cout<<"NO\n";
        else cout<<"YES\n";
    }
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

