#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    map<int,vector<int>> id;
    id[0].push_back(0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ^= a[i-1];
        id[a[i]].push_back(i);
    }
    

    while(q--){
        int l, r;
        cin >> l >> r;
        //cout << l << ' ' << r << '\n';
        if(a[l-1] == a[r])cout << "Yes\n";
        else{
            auto R = *--lower_bound(id[a[l-1]].begin(),id[a[l-1]].end(),r);
            auto L = *lower_bound(id[a[r]].begin(), id[a[r]].end(),l);
         
           
            if(R > L)cout << "Yes\n";
            else cout << "No\n";
        }
    }
    cout << '\n';

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
