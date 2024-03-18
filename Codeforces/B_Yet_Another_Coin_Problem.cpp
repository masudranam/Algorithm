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

int a[N];
vector<int> c;

void solve(){
    int n; cin >> n;
    int ans = n;

    for(int i = 0; i < 10 && i*10 <= n; i++){
        int baki = n - i*10;
        ans = min(ans,i + baki/15 + a[baki%15]);
    }
    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
     c = {1,3,6,10,15};
     for(int i = 1; i < N; i++){
        a[i] = M;
     }
     for(int i = 1; i < N; i++){
        for(auto x : c){
            if(i-x >=0){
                a[i] = min(a[i-x]+1,a[i]);
            }
        }
     }

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

