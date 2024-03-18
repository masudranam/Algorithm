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
    int n, k, x;

    cin >> n >> k >> x;
    if(n < k || x+1 < k){
        cout<<-1<<endl;
        return;
    }
    vector<int> a(n);
    for(int i = 0; i < k; i++){
        a[i] = i;
    }
    for(int i = k; i < n; i++){
        if(x == k)a[i] = k-1;
        else a[i] = x;
    }
    int s = 0;
    for(int i = 0; i < n; i++)s += a[i];
    cout<<s<<endl;

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

