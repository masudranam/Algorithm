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

int f(int l, int p){
    int x = l / p;
    int r = l % p;
    return (p - r)*(x*x) + r*(x+1)*(x + 1);
}

void solve(){
    int n, k;
    cin >> n >> k;
    multiset<ar<int,3>> st;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ar<int,3> t ={f(x,1)-f(x,2),1,x};
        st.insert(t);
    }

    for(int i = 0; i < k-n; i++){
        ar<int,3> t = *st.rbegin();
        st.erase(--st.end());
        int val = f(t[2],t[1]+1)-f(t[2],t[1]+2);
        ar<int,3> x = {val,t[1]+1,t[2]};
        st.insert(x);
    }
    int ans = 0;
    for(ar<int,3> x: st){
        ans += f(x[2],x[1]);
    }
    cout<<ans<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}