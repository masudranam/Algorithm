
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
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    vector<int> p[26];

    for(int i = n-1; i >= 0; i--){
        p[s[i] - 'a'].push_back(i);
    }

    for(int i = 0; i < m; i++){
        int c = t[i] - 'a';
        if(p[c].empty()){
            cout<<"NO\n";
            return;
        }
        for(int j = c-1; j >= 0; j--){
            while(!p[j].empty() && p[j].back() < p[c].back()){
                p[j].pop_back();
            }
        }
        p[c].pop_back();
    }
    cout<<"YES\n";
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

