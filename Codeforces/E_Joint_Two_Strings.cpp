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
    string t; cin >> t;
    vector<string> s(n);

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        int r = sz(t)-1;
        for(int j = sz(s[i])-1; j >= 0 && r >= 0;j--){
            if(s[i][j] == t[r])r--;
        }
        a[i] = r+1;
    }

    sort(all(a));

    int ans = 0;
    for(int i = 0; i < n; i++){
        int l = 0;
        for(int j = 0; j < sz(s[i]) && l < sz(t); j++){
            if(s[i][j] == t[l])l++;
        }
        int x = upper_bound(all(a),l) - a.begin();
        ans += x;
    }
 
    cout<<ans<<endl;
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

