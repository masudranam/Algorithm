#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a;
    int target;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a.push_back(x);
        if(i == f)target = x;
    }
    sort(a.rbegin(),a.rend());

    int l = -1, r = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == target){
            r = i+1;
            if(l == -1)l = i+1;
        }
    }
    //cout << l << ' ' << r << '\n';
    if(r <= k)cout << "YES\n";
    else if(l <= k)cout << "MAYBE\n";
    else cout << "NO\n";
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
