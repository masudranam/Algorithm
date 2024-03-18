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

int get(int n,int x, int y){
        multiset<int> st;
        for(int i = 1; i <= n; i++){
            st.insert(i);
            st.insert(i);
        }

        int ans = 0;
        st.erase(st.find(x));
        st.erase(st.find(y));

        while(sz(st)){
            int cur = *st.rbegin();
            st.erase(--st.end());
            int cur1 = (x*y)/cur;
            auto it = st.lower_bound(cur1);
            if(it == st.end()){
                it--;
            }

            if((*it)*cur > x*y){
                    if(it == st.begin())return 0;
                    it--;
                }
               ans += (*it)*cur;
               st.erase(it);
            }
            return ans;
}

void solve(){
    
    int n; cin >> n;
    int ans = 0;
    for(int i = n/2; i<= n; i++){
        for(int j = n/2; j<=n; j++){
            ans = max(ans,get(n,i,j));
        }
    }
    cout << ans << endl;
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

