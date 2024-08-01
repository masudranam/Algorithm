#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int a[N];
int n;

bool ok(int x, int k,int &extra){
    for(int i = 0; i < n; i++){
        if(a[i] > x){
            extra++;continue;
        }
        k -= (x - a[i]);
        if(k < 0)return false;
    }
    if(k < 0)return false;
    extra = min(extra + k, n);
    return true;
}

void solve(){
    cin >> n;
    int k; cin >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int extra = 0;

    int l = 0, r = 1e18;
    while(r - l > 0){
        int m = (l + r + 1) / 2;
        extra = 0;
        if(ok(m,k,extra)){
            l = m;
        }else r = m - 1;
    }


    extra = 0;
    ok(l,k,extra);
    cout << max(0ll,extra + (l-1)*n + 1) << endl;
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

