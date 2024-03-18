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
    vector<int> a(n+3);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    a[0] = -M*M, a[n+1] = M*M;

    vector<int> s(n+5);
    for(int i = 1; i <= n; i++){
        if(a[i]-a[i-1] > a[i+1] - a[i]){
            s[i+1] = -(a[i+1] - a[i] - 1);
        }
        s[i] += s[i-1];
    }
    vector<int> s1(n+5);

    for(int i = n; i >= 1; i--){
        if(a[i] - a[i-1] < a[i+1] - a[i]){
            s1[i-1] = -(a[i] - a[i-1] - 1);
        }
        s1[i] += s1[i+1];
    }

    int m; cin >>m;
    while(m--){
        int x, y;
        cin >> x >> y;

        int ans = 0;
        if(x < y){
            ans = a[y] - a[x];
            ans += s[y] - s[x];
        }else{
            ans = a[x] - a[y];
            ans += (s1[y] - s1[x]);
        }

        cout << ans << endl;
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

