#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m, d;
    cin >> n >> m >> d;

    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '.')continue;
            int c = 0;
            while(c < i && c < j && j + c + 1 < m && s[i - c - 1][j - c - 1] != '.' && s[i - c - 1][j + c + 1] != '.'){
                c++;
            }
            if(c >= d){
                for(int k = 0; k <= c; k++){
                    s[i-k][j-k] = 'X';
                    s[i-k][j+k] = 'X';
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '*'){
                cout << "NO\n"; return;
            }
        }
    }

    cout << "YES\n";
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

