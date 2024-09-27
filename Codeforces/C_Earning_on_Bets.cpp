#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

<<<<<<< HEAD
bool ok(int x, vector<pair<int,int>>a){
    int t = a.back().first * x;
=======
bool ok(int x, vector<pair<int,int>>&a){
    int t = x;
>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
    int cur = 0;
    int n = a.size();

    for(int i = 0; i < n; i++){
        cur += (t + a[i].first - 1) / a[i].first;
    }
    return cur < t;
}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> a;
<<<<<<< HEAD
=======

>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back({x,i});
    }
<<<<<<< HEAD

    sort(a.begin(),a.end());

    for(int i = 1; i <= 10000; i++){
        if(ok(i,a)){
            vector<int> ans(n);

            int t = a.back().first*i;
=======
            if(ok(M/10,a)){
            vector<int> ans(n);

            int t = M/10;
>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
            for(int j = 0; j < n; j++){
                ans[a[j].second] = (t + a[j].first - 1)/a[j].first;
            }
            print(ans);
            return;
        }
<<<<<<< HEAD
    }
=======
    
>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
    cout << - 1 << '\n';
    
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
<<<<<<< HEAD
}
=======
}
>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
