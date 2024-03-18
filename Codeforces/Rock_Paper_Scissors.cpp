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

    string t = string(n,'P');

    int target = (n/2)+1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R')target--;
    }

    for(int i = n-1; i >= 0 && target > 0; i--){
        if(s[i] == 'R')continue;
        if(s[i] == 'S'){
            t[i] = 'R';
            target--;
        }
        if(s[i] == 'P'){
            t[i] = 'S';
            target--;
        }
    }
    cout << t << endl;
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

