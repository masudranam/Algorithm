#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    int m; cin >> m;
    map<int,int> mp;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        if(i == m-1){
            if(find(b.begin(),b.end(),x) == b.end()){
                cout << "NO\n";
                return;
            }
        }
        mp[x]++;
    }

    for(int i = 0; i < n; i++){
        if(a[i] == b[i])continue;
        if(mp[b[i]] == 0){
            cout << "NO\n";return;
        }
        mp[b[i]]--;
    }
    cout << "YES\n";
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
