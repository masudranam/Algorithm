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

    vector<int> ps(n);
    ps[0] = s[0]-'0';
    for(int i = 1; i < n; i++){
        ps[i] = ps[i - 1] + (s[i] - '0');
    }

    string res;
    int cur = 0;
    for(int i = n-1; i >= 0; i--){
            cur += ps[i];
            res += (cur % 10 + '0');
            cur /= 10;
    }
    
    if(cur){
        res += to_string(cur);
    }
    
    while(res.size() && res.back() == '0'){
        res.pop_back();
    }
    reverse(res.begin(), res.end());

    cout << res << '\n';
    
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
