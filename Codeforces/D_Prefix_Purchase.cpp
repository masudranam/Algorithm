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

vector<int> c(n);
set<int> st;

for(int i = 0; i < n; i++){
  cin >> c[i];
  mp[c[i]] = i;
  st.insert(c[i]);
}

vector<int> id;
    int last = -1;

  for(auto x: st){
    if(mp[x] > last){
        last = mp[x];
        id.push_back(mp[x]);
    }
  }

  int k; cin >> k;
  vector<int> ans(n+1,0);
  ans[id[0]] = k/c[id[0]];
  k %= c[id[0]];

  for(int i = 1; i < sz(id); i++){
    int d = c[id[i]]-c[id[i-1]];
    int extra = min(ans[id[i-1]], k / d);

    k += extra*c[id[i-1]];
    ans[id[i-1]] -= extra;
    ans[id[i]] += k/c[id[i]];
    k = k%c[id[i]];
  }

  for(int i = n-2; i >=0; i--){
    ans[i] = ans[i]+ans[i+1];
  }

  for(int i = 0; i < n; i++){
    cout<<ans[i]<<" \n"[i==n-1];
  }

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

