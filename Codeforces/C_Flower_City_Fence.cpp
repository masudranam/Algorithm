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
    int n; 
    cin >> n;

    vector<int> a(n);
    for(auto &x: a)cin >> x;

    int cur = n, j = n-1, i = 0,last = 0;

    while(j >= 0){
        int cnt = a[j] - last;
        last = a[j];
        int cur = j+1;
        int last_j = j;

        while(j >= 0 && a[j] == a[last_j])j--;
        
        int last_i = i;
        while(cnt && i < n){
            if(a[last_i] == cur)cnt--,i++;
            else break;
        }

        if(cnt){
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";

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

