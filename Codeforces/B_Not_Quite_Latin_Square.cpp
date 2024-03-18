#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    string s[3];
    for(int i = 0; i < 3; i++){
        cin >> s[i];
    }
    vector<int> cnt(5);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(s[i][j] == '?')continue;
            cnt[s[i][j]-'A']++;
        }
    }
    if(cnt[0] == 2)cout <<'A'<<endl;
    else if(cnt[1] == 2)cout <<'B'<<endl;
    else cout <<'C'<<endl;
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

