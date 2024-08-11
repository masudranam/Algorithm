#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, k;
    cin >> n >> k;

    string s; cin >> s;

    map<char,int> mp;

    string t = "";

    for(int i = 0; i < n; i++){
        if(t.empty() || t.back() == s[i])t += s[i];
        else{
            t = "";
            t += s[i];
        }
        if(t.size() == k){
            mp[t.back()]++;
            t = "";
        }
    }
    int res = 0;
    for(auto it : mp){
        res = max(res, it.second);
    }
    cout <<res << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}