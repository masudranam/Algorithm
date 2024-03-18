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
    if(n % 2 == 0){
        cout << -1 << endl;
        return ;
    }

    vector<int> odd;
    for(int i = 1; i <= n*n; i+= 2){
        odd.push_back(i);
    }

    vector<vector<int>>a(n,vector<int>(n,-1));

a[0][0] = odd.back(); odd.pop_back();

    for(int i = 1; i < n; i++){
        a[0][i] = odd.back();
        odd.pop_back();
        a[i][0] = odd.back();
        odd.pop_back();
    }

    int x = n-1, y = n-1;

    while(sz(odd) > 0 && y >= 0 && x >= 0){
        for(int i = 1; i < y && sz(odd) > 1; i++){
            a[i][x] = odd.back(); odd.pop_back();
            a[x][i] = odd.back(); odd.pop_back();
        }
        x--, y--;
    }
    assert(sz(odd) == 0);
    for(int i = 2; i < n*n; i+= 2)odd.push_back(i);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == -1){
                a[i][j] = odd.back();
                odd.pop_back();
            }
        }
    }

    assert(sz(odd) == 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] <<' ';
        }
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

