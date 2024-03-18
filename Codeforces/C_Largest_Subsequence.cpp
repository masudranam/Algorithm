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
    int n; cin >> n;
    string s; cin >> s;

    set<pair<char,int>> st;
    for(int i = 0; i < n; i++){
        st.insert({-s[i],i});
    }

    vector<int> vis(n),v;
    string t;

    while(sz(st)){
        pair<char,int> p = *st.begin();
        st.erase(st.begin());
        if(vis[p.second])continue;
        v.push_back(p.second);
        t += (-p.first);
        while(p.second >= 0 && !vis[p.second]){
            vis[p.second] = true;
            p.second--;
        }
    }
    
    sort(all(v));
    sort(all(t));

    for(int i = 0; i < sz(v); i++){
        s[v[i]] = t[i];
    }
    char c = t.back();
    while(sz(t) && t.back() == c)t.pop_back();
    
    if(is_sorted(all(s)))cout<<sz(t)<<endl;
    else cout<<-1<<endl;
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

