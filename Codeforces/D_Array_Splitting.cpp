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
    int n, k;
    cin >> n >> k;

    vector<int> a(n),sf(n+2);
    vector<ar<int,2>>s;

    for(auto &x: a)cin >> x;


    for(int i = n -1; i >= 0; i--){
       sf[i] = sf[i+1] + a[i];
       if(i)s.push_back({sf[i],i});
    }

    vector<int> id{0,n};
    sort(all(s));
    k--;

    for(int i = sz(s)-1; i >= 0 && k--; i--){
        id.push_back(s[i][1]);
    }

    sort(all(id));
   
    int ans = 0;
    for(int i = 0; i+1 < sz(id); i++){
        ans += (i+1)*(sf[id[i]]-sf[id[i+1]]);
    }

    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

