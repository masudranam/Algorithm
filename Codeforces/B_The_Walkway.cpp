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

int get(int r, int l, int d){
    return (r-l-1)/d;
}

void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m+2);

    a[0] = -d+1, a[m+1] = n+1;

    int tot = 0;
    for(int i = 1; i <= m+1; i++){
        if(i <= m)cin >> a[i];
        tot += get(a[i],a[i-1],d);
    }

    int ans = n+1, cnt = 0;
    for(int i = 1; i <= m; i++){
        int res = tot;
        res -= get(a[i],a[i-1],d);
        res -= get(a[i+1],a[i],d);
        res += get(a[i+1],a[i-1],d);
        res += m-1;
        if(res < ans){
            ans = res;
            cnt = 1;
        }else if(res == ans)cnt++;
    }

    cout << ans <<' '<<cnt<<endl;

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

