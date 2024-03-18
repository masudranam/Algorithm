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

int a[N],b[N];
int n, k;

bool ok(int x){
    for(int i = 1; i <= n; i++){
        if(a[i] >= x)return true;
        int cur = x, need = 0;
        for(int j = i; j <= n && cur; j++){
            need += max(0ll,cur-a[j]);
            if(max(a[j],a[j+1]+1) >= cur && need <= k){
                return true;
            }
            cur--;
        }
    }
    return false;
}


void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[n+1] = 0;
    int l = 1, r = M;
 
    while(r-l>0){
        int m = (l+r+1)/2;
        if(ok(m))l = m;
        else r = m-1;
    }
    cout << l << endl;
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

