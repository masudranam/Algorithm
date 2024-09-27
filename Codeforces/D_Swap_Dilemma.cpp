#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int get(vector<int> a){
    map<int,int> idx;
    
    
    for(int i = 0; i < a.size(); i++){
        idx[a[i]] = i;
    }

    int res = 0;
    auto as = a; sort(as.begin(), as.end());

    for(int i = 0; i < a.size(); i++){
        if(idx[as[i]] == i)continue;
        int j = idx[as[i]];
        res += (2*(i - j) - 1);
        idx[a[i]] = j; 
        swap(a[i], a[j]);
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    auto as = a, bs = b;
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    if(as == bs && get(a) % 2 == get(b) % 2)cout << "YES\n";
    else cout << "NO\n";
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
