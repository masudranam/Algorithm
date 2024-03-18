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

    vector<int> id;

    for(int i = 0; i < n; i++){
        if(s[i] == 'A')id.push_back(i);
    }
    vector<int> vis(n);

    for(int i = sz(id)-1; i >= 0; i--){
        int j = id[i];
        while(j+1 < n && s[j] == 'A' && s[j+1] == 'B' && !vis[j]){
            swap(s[j],s[j+1]);
            vis[j] = 1;
            j++;
        }
    }
    int ans = 0;
    for(auto x: vis)ans += x;
    cout<<ans<<endl;
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

