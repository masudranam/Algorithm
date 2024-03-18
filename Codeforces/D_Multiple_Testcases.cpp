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
    multiset<int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert(x);
    }

    vector<pair<int,int>>c;
    vector<int> a(k);
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }

    for(int i = k-1; i >= 0; i--){
        if(c.empty())c.push_back({a[i],i+1});
        else if(c.back().first != a[i]){
            c.push_back({a[i],i+1});
        }
    }
    c.push_back({0,0});
    
    vector<vector<int>> ans;
   int cnt = 100;
    while(sz(st) > 0){
        vector<int> cur;
     
        for(int i = 0; i + 1 < sz(c) && sz(st); i++){
            while(sz(cur) < c[i].first && sz(st)){
                auto it = st.upper_bound(c[i].second);
                if(it == st.begin())break;
                it--;
                cur.push_back(*it);
                st.erase(it);
            }
            if(sz(st) && *st.begin() > c[i].second)break;
        }
        if(sz(cur))ans.push_back(cur);
    }

   cout << sz(ans) << endl;
   for(auto x : ans){
    cout << sz(x)<<' ';
    reverse(all(x));
        for(auto y : x)cout << y <<' ';
        cout << endl;
   }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

