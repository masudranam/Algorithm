#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int a[N], b[N];
int h, n;

bool ok(int x){
    int cur = 0;
    for(int i = 0; i < n; i++){
        cur += ((x/b[i]) + 1) * a[i];
    }
    return cur >= h;
}

void solve(){
    cin >> h >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int l = 1, r = 1e12;
    while(r - l > 0){
        int m = (l + r)/2;
        if(ok(m-1))r = m;
        else l = m + 1;
    }
    cout << l << '\n';
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

