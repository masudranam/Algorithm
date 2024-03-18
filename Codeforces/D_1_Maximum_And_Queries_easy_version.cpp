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

int get(vector<int> a, int k){
    int n = sz(a);
    int ans = 0;
    for(int i = 63; i >= 0; i--){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(a[j]&(1ll<<i))continue;
            cnt += (1ll<<i)-(a[j]&((1ll<<i)-1));
            if(cnt > k)break;
        }
        if(cnt <= k){
            ans += (1ll<<i);
            k-=cnt;
            for(int j = 0; j < n; j++){
                if(a[j]&(1ll<<i))continue;
                a[j] -= (a[j]&((1ll<<i)-1));
                a[j]|=(1ll<<i);
            }
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    while(q--){
        int k; cin >> k;
        cout<<get(a,k)<<endl;
    }


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

