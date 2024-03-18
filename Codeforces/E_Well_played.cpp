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
    int n, a, b;
    cin >> n >> a >> b;

    vector<ar<int,3>> v;
    int s = 0;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        s += y;
        v.push_back({max(0ll,x-y),x,y});
    }

    sort(all(v)); reverse(all(v));
    vector<int> ps(n+1);

    for(int i = 1; i <= n; i++){
        ps[i] = ps[i-1] + v[i-1][0];
    }

    int ans = s;
    if(b == 0){
        cout<<s<<endl;
        return;
    }


    for(int i = 0; i < n; i++){
        int x = v[i][1], y = v[i][2];
        int extra = 0;

        if(b <= i){
            extra = ps[b-1];
        }else{
            extra = ps[min(n,b)] - v[i][0];
        }
        
        extra += max(0ll,(x<<a)-y);
        ans = max(ans,extra+s);
    }
    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

