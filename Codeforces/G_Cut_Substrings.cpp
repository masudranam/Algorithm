#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 5e2 + 10;

bool match[N];
pair<int,int> dp[N][N];
int n, m;

pair<int,int> Merge(pair<int,int> a, pair<int,int> b){
    if(a.first > b.first) return b;
    if(b.first > a.first) return a;
    return {a.first , (a.second + b.second) % M};
}

pair<int,int> get(int i, int last){
    if(i >= n) return {0, 1};
    pair<int,int> &ret = dp[i][last];
    if(ret.first != -1) return ret;

    ret = {M, 0};
    if(match[i]){
        auto p = get(i+m, i + m);
        p.first++;
        ret = Merge(ret, p);
    }
    if(i - m + 1 < last || !match[i - m + 1]){
        ret = Merge(ret,  get(i+1, last));
    }
    return ret;
}

void solve(){
    string s, t;
    cin >> s >> t;
    n = s.size(), m = t.size();
    memset(match, 0, sizeof(match));
    
    for(int i = 0; i < n; i++){
        if(s.substr(i, m) == t){
            match[i] = 1;
        }
    }

    memset(dp, -1, sizeof(dp));
    

    auto res = get(0, 0);
    cout << res.first <<' '<< res.second << '\n';
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