#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 5e5 + 10;

void solve(){
  int n; cin >> n;
  vector<int> a(n);

  for(auto &x : a) cin >> x;
  vector<int> b;

  int mx = 0;
  for(int i = 0; i < n; i++){
   if(a[i] < mx){
      b.push_back(mx - a[i]);
   }else{
      mx = a[i];
   }
  }

   sort(b.begin(), b.end());
   
   
    int res = 0, add = 0;
    if(b.size()) res = accumulate(b.begin(), b.end(), add) + b.back();
    cout << res << '\n';
 
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