#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    if(s[0] != t[0]){
        cout << -1 << '\n';return;
    }

    if(s == t){
        cout << 0 << '\n';return;
    }

    while(s.size() && t.size() && s.back() == t.back()){
        s.pop_back();
        t.pop_back();
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    while(s.size() && t.size() && s.back() == t.back()){
        s.pop_back();
        t.pop_back();
    }
    if(s.size() == 0 || t.size() == 0){
        cout << 1 << '\n';
    }else{
        cout << 2 << '\n';
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
