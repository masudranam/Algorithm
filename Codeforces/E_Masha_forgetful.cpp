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
    int n, m;
    cin >> n >>  m;
    map<string,vector<int>>mp;

    string s;

    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            for(int len : {2, 3}){
                if(j + len <= m && mp.find(s.substr(j,len)) == mp.end()){
                    mp[s.substr(j,len)] = {j,j+len-1,i};
                }
            }
        }
    }

    cin >> s;
    
    vector<int> dp(m+1);
    dp[m] = 1;


    for(int i = m-2 ; i >= 0; i--){
        string t;
        for(int len : {2, 3}){
            if(len + i <= m && dp[len+i]){
                t = s.substr(i,len);
                if(mp.find(t) != mp.end()){
                    dp[i] = 1;
                }
            }
        }
    }

    if(dp[0] == 0){
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> ans;

    int i = 0;
    while(i + 1 < m){
        string t;
        for(int len : {2, 3}){
            if(i + len <= m && dp[i+len]){
                t = s.substr(i,len);
                if(mp.find(t) != mp.end()){
                    ans.push_back(mp[t]);
                    i += len;
                    break;
                }
            }
        }
    }

    cout << sz(ans) << endl;
    for(auto it : ans){
        cout<< it[0] + 1 <<' '<< it[1] + 1 <<' '<< it[2] << endl;
    }

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

