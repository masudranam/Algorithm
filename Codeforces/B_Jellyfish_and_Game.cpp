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
    int n, m, k;
    cin >> n >> m >> k;

    multiset<int> a,b;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        b.insert(x);
    }

    k = min(k, 20 + k%2);
   
    for(int i = 1; i <= k; i++){
            if(i&1){
                int ia = *a.begin(), ib = *b.rbegin();
                if(ia < ib){
                    a.erase(a.begin()), b.erase(--b.end());
                    a.insert(ib); b.insert(ia);
                }
            }else{
                int ia = *a.rbegin(), ib = *b.begin();
                if(ia > ib){
                    a.erase(--a.end()), b.erase(b.begin());
                    a.insert(ib), b.insert(ia);
                }
            }
    }
  
    int sum = 0;
    for(auto x : a)sum += x;
    cout<<sum<<endl;

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

