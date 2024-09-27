#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

string s;
vector<int> g[N];

int dfs(int u){
    int sum = 0;
    for(auto v : g[u]){
        sum += dfs(v);
    }
   
    int cnt_p = 0, cnt_s = 0;
    for(auto v : g[u]){
        if(s[v] == 'S')cnt_s++;
        else if(s[v] == 'P')cnt_p++;
    }

    if(s[u] == 'S'){
        return sum + cnt_p;
    }else if(s[u] == 'P'){
        return sum + cnt_s;
    }else{
        if(cnt_p > cnt_s){
            s[u] = 'P';
            return sum + cnt_s;
        }else if(cnt_p < cnt_s){
            s[u] = 'S';
            return sum + cnt_p;
        }else{
            return sum + cnt_p;
        }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
    }
    for(int i = 1; i < n; i++){
        int p; cin >> p, p--;
        g[p].push_back(i);
    }
    cin >> s;
   

    cout << dfs(0) << '\n';
    
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

