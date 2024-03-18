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



void solve(){
  int n; cin >> n;
  map<int,int>mp;
  vector<int> a(n);
  set<int> st;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    st.insert(a[i]);
  }

  vector<int> b(all(st));

  int m = sz(b);
  for(int i = 0; i < m; i++){
    mp[b[i]] = i;
  }

  int ans = 0;
  vector<int> c(n);

  for(int i = 0; i < n; i++){
    int id = mp[a[i]];
    int x = c[id] + 1;
    int y = 0;
    if(id-1 >= 0){
        y = c[id-1] + 1;
    }
    c[id] = max(x,y);
    ans =max(ans,c[id]);
  }

    cout<<n-ans<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

