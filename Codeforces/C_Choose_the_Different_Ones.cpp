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
    int n, m, k;
    cin >> n >> m >> k;
    set<int> a, b;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x <= k)a.insert(x);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        if(x <= k)b.insert(x);
    }

    set<int> c;
    for(int i = 1; i <= k; i++){
        if(a.find(i) == a.end() && b.find(i) == b.end()){
            cout << "NO\n"; return;
        }
        if(a.find(i) != a.end() && b.find(i) != b.end()){
            c.insert(i);
            a.erase(i);
            b.erase(i);
        }
    }

    if(sz(a) + sz(b) + sz(c) == k && (sz(a) + sz(c)) >= k/2 && (sz(b) + sz(c)) >= k/2){
        cout <<"YES\n";
    }else{
        cout <<"NO\n";
    }


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

