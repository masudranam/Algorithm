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
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    int l = 0, j = 0;
    for(int i = 1; i < n; i++){
        if(s[i] < s[j])l = i, j = 0;
        else if(s[i] == s[j])j++;
        else break;
    }
    s = s.substr(0,l+1);
    while(sz(s) < k)s = s+s;
    while(sz(s) > k)s.pop_back();
    cout << s << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

