#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> p(n), vis(n);

    for(int i = 0; i < n; i++){
        cin >> p[i], p[i]--;
    }
    string s; cin >> s;
    vector<int> res(n);

    for(int i = 0; i < n; i++){
        if(vis[i] == 1)continue;
        if(p[i] == i){
            res[i] = (s[i] == '0');
            continue;
        }
        int cnt = 0, x = i;
        vector<int> t;
        while(true){
            if(vis[x])break;
            if(s[x] == '0')cnt++;
            vis[x] = 1;
            t.push_back(x);
            x = p[x];
        }
        for(auto it : t)res[it] = cnt;
    }
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
