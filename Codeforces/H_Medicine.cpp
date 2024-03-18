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
const int N = 3e5 + 10;

int a[N],b[N];
int k, n;

bool ok(int x){
    int res = 0;
    for(int i = 0; i < n; i++){
        if(x <= a[i])res += b[i];
    }
    return k >= res;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int l = 1, r = M*M;
    while(r-l > 0){
        int m1 = (l+r)/2;
        if(ok(m1))r = m1;
        else l = m1+1;
    }
    cout<<l<<endl;

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

