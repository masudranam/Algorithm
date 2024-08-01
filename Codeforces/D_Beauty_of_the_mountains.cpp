#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    string s[n];
    vector<vector<int>> a(n+1,vector<int>(m+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int s0 = 0, s1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '0')s0 += a[i+1][j+1], a[i+1][j+1] = 0;
            else s1 += a[i+1][j+1], a[i+1][j+1] = 1;
        }
    }

    if(s0 == s1){
        cout << "YES\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    vector<int> vis(n*m + 1);

    int d = abs(s0 - s1);

    vector<int> pos, neg;

    for(int i = k; i <= n; i++){
        for(int j = k; j <= m; j++){
            int one = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];
            int zero = k*k - one;
            if(one == zero)continue;
            pos.push_back(abs(one-zero));
        }
    }

    int g = 0;
    for(auto dv : pos){
        g = __gcd(g,dv);
    }

    if(pos.size() && d % g == 0) cout << "YES\n";
    else cout << "NO\n";
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

