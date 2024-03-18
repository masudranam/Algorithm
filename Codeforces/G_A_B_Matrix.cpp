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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(n*a != m*b){
        cout <<"NO\n";return;
    }

    vector<vector<char>>s(n,vector<char>(m,'0'));
    int x = 0;
    for(x = 1; x < m; x++){
        if((x*n) % m == 0)break;
    }

    for(int i = 0, y = 0; i < n; i++, y += x){
        for(int j = 0; j < a; j++){
            s[i][(j+y)%m] = '1';
        }
    }

    cout <<"YES\n";
    for(int i = 0; i < n; i++){
       for(auto c : s[i])cout<<c;
       cout << endl;
    }
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

