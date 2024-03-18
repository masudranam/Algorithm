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
const int N = 1e7 + 10;
int f[N],can[N];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 0;i < n; i++){
        int x; cin >> x;
        f[x]++;
    }
    for(int i = 1; i < N; i++){
        f[i] += f[i-1];
    }

    vector<ar<int,2>> a;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        a.push_back({x,i+1});
    }
    sort(all(a));

    vector<int> ans;

    for(int i = N-2; i >= 0; i--){
        can[i] = (i+1)*k - f[i];
        if(can[i] < 0){
            cout<<-1<<endl;
            return;
        }
    }
    
    int picked = 0;
    reverse(all(a));

    for(int i = 0; i+1 < N; i++){
        while(sz(a) && a.back()[0] < i)a.pop_back();
        while(can[i] > sz(ans) && sz(a) && a.back()[0] >= i){
            ans.push_back(a.back()[1]);
            a.pop_back();
        }
    }
    cout<<sz(ans)<<endl;

    print(ans);
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

