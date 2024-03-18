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

    vector<pair<char,int>>a;
    for(int i = 0; i < n; i++){
        if(a.empty() || a.back().first != s[i]){
            a.push_back({s[i],1});
        }else{
            a.back().second++;
        }
    }

    bool ok = 1;
    for(int i= 0; i < sz(a); i+=2){
        ok &= (a[i].second%2 == 0);
    }
    if(ok){
        cout<<"Yes\n";return;
    }
    ok = 1;
    for(int i = 1; i < sz(a); i+=2){
        ok &= (a[i].second%2 == 0);
    }
    if(ok)cout<<"Yes\n";
    else cout<<"No\n";
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

