#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> a(4);
    for(int i = 0; i < 4*n; i++){
        if(s[i] == '?')continue;
        a[s[i]-'A']++;
    }

    a[0] = min(a[0], n);
    a[1] = min(a[1], n);
    a[2] = min(a[2], n);
    a[3] = min(a[3], n);

    cout << a[0] + a[1] + a[2] + a[3] << '\n';
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