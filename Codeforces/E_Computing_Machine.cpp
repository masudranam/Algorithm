#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    string s, t;
    cin >> s >> t;

    auto get = [&](int i, int l, int r){
        if(s[i] == '1')return 1;
        bool f = (i - 1 >= l && t[i-1] == '1') || (i - 2 >= l && s[i-2] == '0');
        f &= ((i+1 <= r && t[i+1] == '1') || (i+2 <= r && s[i+2] == '0'));
        return f?1:0;
    };

    vector<int> p(n+1);
    for(int i = 0; i < n; i++){
        p[i+1] = p[i] + get(i,0,n-1);
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        l--;
        int ans = 0;
        if(r - l <= 5){
            for(int i = l; i < r; i++){
                ans += get(i,l,r-1);
            }
        }else{
            ans = p[r - 2] - p[l + 2];
            for(int i : {l, l + 1, r-2, r-1}){
                ans += get(i, l, r-1);
            }
        }
        cout << ans << '\n';
    }
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
