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
    int g = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    vector<int> b;
    for(int i = 1; i < n; i++){
        if(a[i] % a[0]){
            b.push_back(a[i]);
        }
    }

    sort(b.begin(),b.end());
    for(int i = 1; i < b.size(); i++){
        if(b[i] % b[0]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
