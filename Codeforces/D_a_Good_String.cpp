#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int get(string s, char c){
    //cout << s << ' ' << c << '\n';
    if(s.size() == 1){
        if(s[0] == c)return 0;
        else return 1;
    }
    string l = s.substr(0,s.size()/2), r = s.substr(s.size()/2);
    int cntl = count(l.begin(),l.end(),c);
    int cntr = count(r.begin(),r.end(),c);
    return min(get(l,c+1) + r.size() - cntr, get(r,c+1) + l.size() - cntl);
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    cout << get(s,'a') << '\n';
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
