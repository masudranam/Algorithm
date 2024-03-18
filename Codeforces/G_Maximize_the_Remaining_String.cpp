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
    string s;
    cin >> s;

    set<char> st;
    vector<int> g[26];
    for(int i = sz(s) - 1; i >= 0; i--){
        g[s[i]-'a'].push_back(i);
        st.insert(s[i]);
    }

    string ans;

    while(sz(st)){
       
        char c;
        for(auto i = st.rbegin(); i != st.rend(); i++){
            bool ok = 1;
            int x = g[(*i)-'a'].back();

            for(auto it = st.begin(); it != st.end(); it++){
                ok &= (g[(*it)-'a'][0] >= x);
            }
            if(ok){
                c = *i;
                for(auto it = st.begin(); it != st.end(); it++){
                    while(sz(g[(*it)-'a']) && g[(*it)-'a'].back() <= x){
                        g[(*it)-'a'].pop_back();
                    }
                }
                break;
            }
        }
        ans += c;
        st.erase(c);
    }
   cout << ans << endl;
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

