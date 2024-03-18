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
    int n, k;
    cin >> n >> k;

    vector<int> ans(n);
    set<int> st;
    for(int i = k+1; i <= n+k; i++)st.insert(i);
 

    vector<pair<int,int>> a;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a.push_back({x,i});
    }

    sort(all(a),greater<pair<int,int>>());

    int s = 0;
    for(auto it : a){
       auto it1 = st.lower_bound(it.second);
       int x = *it1;
      // cout <<it.first <<' '<<it.second<<' '<<*it1<<endl;
       st.erase(it1);
       ans[it.second-1] = x;
       s += (x - it.second)*it.first;      
    }
    cout << s << endl;
    print(ans);
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

