#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;
int cnt[N];

void solve(){
    
   int t; cin >> t;
   vector<string> s(t);
   for(int i = 0; i < t; i++){
    cin >> s[i];
   }
   vector<pair<int,int>> mx(t, {0,0});
   for(int i = 0; i < N; i++){
    string ss = to_string(i);

    for(int j = 0; j < t; j++){
        if(s[j].size() != ss.size())continue;
        bool ok = 1;
        for(int k = 0; k < ss.size(); k++){
            if(ss[k] == s[j][k] || s[j][k] == '?')continue;
            ok = false;
        }
        if(ok)mx[j] = max(mx[j], {cnt[i], i});
    }
   }
   for(int i = 0; i < t; i++){
    cout << mx[i].second << '\n';
   }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

    for(int i = 0; i < N; i++){
        int res = 0, x = i;
        while(x){
            if(x&1)res++;
            x /= 2;
        }
        cnt[i] = res;
    }

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
