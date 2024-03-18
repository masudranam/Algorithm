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
    string s; cin >> s;
    int n = s.size();

    vector<int> v[26];
    for(int i = 0;i < n; i++){
        v[s[i]-'a'].push_back(i+1);
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        if(r == l){
            cout<<"Yes\n";
            continue;
        }
        if(s[l-1] != s[r-1]){
            cout <<"Yes\n";continue;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            int x = upper_bound(all(v[i]),r) - lower_bound(all(v[i]),l);
            if(x)cnt++;
        }
        if(cnt >= 3){
            cout <<"Yes\n";
        }else{
            cout <<"No\n";
        }
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

