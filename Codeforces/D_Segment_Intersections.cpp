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
    int n, k;
    cin >> n >> k;

    int l1, r1 , l2 , r2;
    cin >> l1 >> r1 >> l2 >> r2;

    int left = max(l1,l2), right = min(r1,r2);
    int overlap = max(0ll,right-left), extra = max(-(right-left),0ll);
    int  len = max(r1,r2)-min(l1,l2);
    

    int ans = M*M;
    k -= overlap*n;
    if(k <= 0){
        cout<<0<<endl;
        return;
    }
    
    int tmp = 0, ache = 0;

    for(int i = 0; i < n; i++){
        ache += (len - overlap);
        tmp += extra;
        int lagbe = max(0ll,k-ache);
        ans = min(ans,lagbe*2 + min(k,ache)+tmp);
    }

    cout<<ans<<endl;

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

