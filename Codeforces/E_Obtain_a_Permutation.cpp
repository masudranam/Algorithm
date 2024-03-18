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
int n, m;

int get(int j, int x){
    if((x-j)%m || ((x-j)/m) >= n)return -1;
    return ((x-j)/m)+1;
}

void solve(){
    cin >> n >> m;
    int a[n+1][m+1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;
    
    for(int j = 1; j <= m; j++){
        map<int,int> mp;
        for(int i = 1; i <= n; i++){
            int x = get(j,a[i][j]);
            if(x == -1)continue;
            x = i - x;
            if(x < 0)x += n;
            mp[x]++;
        }

        int cur = n;
        for(auto it : mp){
            cur = min(cur, it.first + n - it.second);
        }
        ans += cur;
    }

    cout << ans << endl;
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

