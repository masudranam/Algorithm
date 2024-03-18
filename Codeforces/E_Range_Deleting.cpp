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
    int n, x;
    cin >> n >> x;

    vector<int> sfmx(x+2),sfmn(x+2,x+1),a(n);
    int cur = x;
    set<int> st; st.insert(x+1);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        auto it = st.upper_bound(a[i]);
        if(it != st.end())cur = min(cur,*it);
        st.insert(a[i]);
    }

    st.clear();
    st.insert(x+1);

    for(int i = n-1; i >= 0; i--){
        if(*st.begin() < a[i]){
            sfmn[a[i]] = *st.begin();
        }

        auto it = st.lower_bound(a[i]);
        if(it != st.begin()){
            it--;
            sfmx[a[i]] = *it;
        }
        st.insert(a[i]);
    }

    for(int i = x; i >= 1; i--){
        sfmx[i] = max(sfmx[i+1],sfmx[i]);
        sfmn[i] = min(sfmn[i+1],sfmn[i]);
    }

    int ans = 0;

    for(int i = cur; i >= 1; i--){
        int l = i, r = x;
        while(r-l > 0){
            int m = (l+r)/2;
            if(sfmx[m+1] > m || sfmn[m+1] < i)l = m+1;
            else r = m;
        }
        ans += (x-r+1);
    }
    
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

