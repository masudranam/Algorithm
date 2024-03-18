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

    string s[n+5];

    s[0] = string(m+2,'.');

    for(int i = 1; i <= n; i++){
        string t; cin >> t;
        t = "."+t+".";
        s[i] = t;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == 'L'){
                if(s[i][j+1] != 'R'){
                    cout<<"-1\n";return;
                }
            }
            if(s[i][j] == 'R'){
                if(s[i][j-1] != 'L'){
                    cout<<-1<<endl;return;
                }
            }
            if(s[i][j] == 'U'){
                if(s[i+1][j] != 'D'){
                    cout<<-1<<endl;return;
                }
            }
            if(s[i][j] == 'D'){
                if(s[i-1][j] != 'U'){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }


string c = "WB";
int f = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == 'L'){
                for(int k = i; k <= n; k++){
                    if(s[k][j] == 'L'){
                        s[k][j] = c[f%2];
                        s[k][j+1] = c[(f+1)%2];
                        f++;
                    }
                }
            }

            if(s[i][j] == 'U'){
               
                for(int k = j; k <= m; k++){
                    if(s[i][k] == 'U'){
                        s[i][k] = c[f%2];
                        s[i+1][k] = c[(f+1)%2];
                        f++;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= m; j++){
            cnt += s[i][j] == 'W';
            cnt -= s[i][j] == 'B';
        }
        if(cnt){
            cout<<-1<<endl;
            return;
        }
    }
    for(int j = 1; j <= m; j++){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += s[i][j] =='W';
            cnt -= s[i][j] == 'B';
        }
        if(cnt){
            cout<<-1<<endl;
            return;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout<<s[i][j];
            if(j == m)cout<<endl;
        }
    }


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

