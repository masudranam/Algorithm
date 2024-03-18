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
    vector<int> a(n), b(n);

    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    vector<ar<int,3>> v;
    for(int i = 0; i < n; i++){
        v.push_back({a[i]+b[i],a[i],b[i]});
    }

    sort(all(v));

    for(int i = 0; i < n; i++){
        cout << v[i][1] <<' ';
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << v[i][2] <<' ';
    }
    cout << endl;
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

