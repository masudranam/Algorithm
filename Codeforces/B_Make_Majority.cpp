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
    string t;
    for(int i = 0; i < n; i++){
        if(i){
            if(s[i] == '1') t += s[i];
            else{
                if(t.back() == '0')continue;
                t += s[i];
            }
        }else{
            t += s[i];
        }
    }
    int cnt = 0;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '1')cnt++;
        else cnt--;
    }
    if(cnt > 0)cout << "Yes\n";
    else cout << "No\n";
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