#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, x;
    cin >> n >> x;

    set<int> st;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int mask = 0; mask < (1<<(n/2)); mask++){
        int s = 0;
        for(int i = 0; i < n/2; i++){
            if(mask & (1 << i)){
                s += a[i];
            }
        }
        st.insert(s);
    }
    int ans = 0;

    for(int mask = 0; mask < (1<<(n - n/2)); mask++){
        int s = 0;
        for(int i = 0; i < (n - n/2); i++){
            if(mask & (1<<i)){
                s += a[n/2 + i];
            }
        }
        auto it = st.upper_bound(x - s);
        if(it != st.begin()){
            it--;
            ans = max(ans, s + *it);
        }
    }

    cout << ans << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
