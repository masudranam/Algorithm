#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    if(a == b){
        cout << 0 << '\n';
        return;
    }
    if(k  == 1){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += a[i] != b[i];
        }
        cout << cnt << '\n';
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                cout << i + 1 << ' '<< b[i] << '\n';
            }
        }
        return;
    }

    int l = 0;
    array<int,3> mx{0, 0, 0};

    for(int i = 0; i < n; i++){
        if(b[l] == b[i]){
            mx = max(mx, {i - l + 1, l , i});
        }else{
            l = i;
        }
    }
    if(mx[0] < k){
        cout << - 1 << '\n';
        return;
    }

     l = mx[1]; int r = l + k - 1;

    vector<pair<int,char>> res;

    for(int i = 0; i <= l; i++){
        res.push_back({i + 1, b[i]});
    }
     

    for(int i = n - k; i >= l; i--){
        res.push_back({i + 1, b[i + k - 1]});
    }
    cout << res.size() << '\n';
    for(auto it : res){
        cout << it.first <<' ' << it.second << '\n';
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
