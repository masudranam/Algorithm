#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    string s; cin >> s;
    vector<int> cnt(26);
    for(auto c : s)cnt[c-'a']++;
    char ch = 'a';
    for(int i = 0; i < 26; i++){
        if(cnt[i] == 0){
            ch = (char)(i + 'a');
        }
    }

    for(int i = 1;i < s.size(); i++){
        if(s[i] == s[i-1]){
            cout << s.substr(0,i) + ch + s.substr(i) << '\n';
            return;
        }
    }
    s += ch;
    cout << s << '\n';
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

