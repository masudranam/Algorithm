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
if(n == 1){
    if(s[0] == 'U')cout <<"YES\n";
    else cout << "NO\n";
    return;
}
if(n == 2){
    int cnt = 0;
    cnt += s[0] == 'U';
    cnt += s[1] == 'U';
    if(cnt  == 1)cout <<"YES\n";
    else cout << "NO\n";
    return;
}
int cnt = 0;
for(int i = 0; i < n; i++){
    cnt += s[i] == 'U';
}
if(cnt%2 == 1)cout << "YES\n";
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

