#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);

    map<int,vector<int>>mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        int x = a[i];
        a[i] ^= (a[i-1]);
        if(x)mp[a[i]].push_back(i);
    }

    while(q--){
        int l, r; 
        cin >> l >> r;
        if((a[r]^a[l-1]) == 0){
            cout << "YES\n";continue;
        }
        cout << (a[r]^a[l]) <<'\n';
        auto &v = mp[a[r]];
        print(v);
        auto it =upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),l);
        if(it > 1)cout << "YES\n";
        else cout << "NO\n";
    }
    cout << '\n';
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

