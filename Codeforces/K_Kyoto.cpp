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
int val[26][26];

void solve(){
  
    string t; cin >> t;
    int n; cin >> n;
    vector<pair<int,string>>ans;

    for(int i = 0; i < n; i++){
        string tt; cin >> tt;
        int res = 0;
        for(int j = 0; j < sz(tt); j++){
            res += val[t[j]-'a'][tt[j]-'a'];
        }
        ans.push_back({res,tt});
    }
    sort(all(ans));
    for(auto it: ans){
        cout<<it.second<<' '<<it.first<<endl;
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
  vector<string> s{"qwertyuiop","asdfghjkl","zxcvbnm"};

    for(int i = 0; i < 3; i++){
        for(int j =0; j < sz(s[i]); j++){
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < sz(s[k]); l++){
                    int x = s[i][j]-'a', y = s[k][l]-'a';
                    val[x][y] = abs(i-k)+abs(j-l);
                }
            }
        }
    }
  

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

