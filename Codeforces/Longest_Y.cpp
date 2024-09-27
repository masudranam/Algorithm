#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;
int n , k;
vector<int> a, b;

bool ok(int x){
    int m = a.size();
    int res =  k + 1;
    for(int i = 1; i + x <= m; i++){
        int mid = i + (x / 2);
        int cur = (mid - i + 1) * a[mid] - (b[mid] - b[i - 1]);
        cur += ((b[i + x - 1] - b[mid - 1]) - (a[mid] * (i + x - mid)));
        res = min(res, cur);
    }
    return res <= k;
}

void solve(){
    string s; cin >> s;
    cin >> k;
    s = 'Y' + s;
    n = s.size();

    for(int i = 0; i < n; i++){
        if(s[i] == 'Y'){
            a.push_back(i - (int)a.size());
            b.push_back(i - (int)b.size());
            if(b.size() > 1){
                b.back() += b[(int)b.size() - 2];
            }
        }
    }

    int l = 0, r = n + 1;
    while(r - l > 0){
        int m = (l + r + 1) / 2;
        if(ok(m))l = m;
        else r = m - 1;
    }
    cout << l << '\n';
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
