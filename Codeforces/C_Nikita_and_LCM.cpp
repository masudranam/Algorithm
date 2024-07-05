#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;


int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    set<int> st, d;
    for(int i = 0; i < n; i++){
        if(a.back() % a[i]){
            cout << n << '\n';
            return;
        }
        st.insert(a[i]);
    }

    for(int i = 1; i * i <= a.back(); i++){
        if(a.back() % i)continue;
        d.insert(i);
        d.insert(a.back() / i);
    }

    int ans = 0;
    for(auto d1 : d){
        if(st.find(d1) != st.end())continue;
        int l = 1, cnt = 0;
        for(int i = 0; i < n; i++){
            if(d1 % a[i] == 0){
                cnt++, l = lcm(a[i], l);
            }
        }
         ans = max(ans, cnt);
    }

    cout << ans << '\n';
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
