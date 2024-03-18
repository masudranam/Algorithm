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

char get(int i, int j){
    int x = (i + j) % 25;
    return ('a' + x);
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>>v(n,vector<char>(m,'a'));
    int cnt = 0;
    if(n%2){
        if(k < m/2){
            cout <<"NO\n";return;
        }
        for(int i = 0; i < m; i += 2){
            v[n-1][i] = v[n-1][i+1]= get(n-1,i);
        }
        n--;
        k -= m/2;
    }else if(m % 2){
        int baki = (n*m)/2 - k;
        if(baki < n/2){
            cout << "NO\n";return;
        }

        for(int i = 0; i < n; i += 2){
           v[i][m-1] = v[i+1][m-1] = get(i,m-1);
        }
        m--;
    }

    if(k % 2){
        cout <<"NO\n";
        return;
    }

    for(int i = 0; i < n; i += 2){
        for(int j = 0; j < m; j += 2){
            v[i][j] = v[i+1][j] = get(i,j);
            v[i][j+1] = v[i+1][j+1] = get(i,j+1); 
        }
    }

    for(int j = 0; j < m; j += 2){
        for(int i = 0; i < n; i++){
            if(k > 0){
                v[i][j] = v[i][j+1] = get(i,j);
                k--;
            }
        }
    }

    cout <<"YES\n";
    for(auto x: v){
        for(auto c: x)cout << c;
        cout << endl;
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

