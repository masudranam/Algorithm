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

int n, m, a[N], b[N];

bool ok(int x){
    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }
    int m1 = m;
    int extra = 0;
    for(int i = n-1; i >= 0; i--){
        if(b[i] == 0)continue;
        int baki = x-i-1;
        if(baki <= 0)return false;
        int x = min(extra,b[i]);
        b[i] -= x, extra -= x;

        int lagbe = (b[i]+baki-1)/baki;
        m1 -= lagbe; 
        if(m1 < 0)return false;

        extra += (lagbe*baki - b[i]);
    }
    return m1 >= 0;
}


void solve(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = 0,  r = M*M;
    while(r-l > 0){
        int mid = (l+r)/2;
        if(ok(mid))r = mid;
        else l = mid+1;
    }

    cout<<r<<endl;
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

