#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x : a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int k; cin >> k;
    string s; cin >> s;

    vector<int> res(n);
    int p = k&1;

    for(int i = 0; i < n; i++){
        if(p){
            s[i] = (s[i] == '0'?'1':'0');
        }
        if(s[i] == '0' && k > 0){
            k--;
            s[i] = '1';
            res[i]++;
        }
    }
    if(k > 0){
        res[n-1] += k;
        if(k&1)s[n-1] = (s[n-1] == '0'?'1':'0');
    }
    cout << s <<'\n';
    print(res);
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
