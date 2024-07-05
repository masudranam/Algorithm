#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(is_sorted(a.begin(),a.end())){
        cout << "Yes\n";return;
    }
    for(int i = 1; i < n; i++){
        vector<int> b;
        for(int j = i; j < n; j++)b.push_back(a[j]);
        for(int j = 0; j < i; j++)b.push_back(a[j]);
        if(is_sorted(b.begin(),b.end())){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n"
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
