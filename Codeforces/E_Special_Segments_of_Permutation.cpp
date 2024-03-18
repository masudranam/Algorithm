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
    vector<int>a(n+1),id(n+1),pf(n+2),sf(n+2);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        id[a[i]] = i;
    }

    stack<pair<int,int>>st;
    st.push({M,0});

    for(int i = 1; i <= n; i++){
       while(st.top().first < a[i])st.pop();
       pf[i] = st.top().second;
       st.push({a[i],i});
    }   
    while(sz(st) > 0)st.pop();

    st.push({M,n+1});

    for(int i = n; i >= 1; i--){
        while(st.top().first < a[i])st.pop();
        sf[i] = st.top().second;
        st.push({a[i],i});
    }
    
    int ans = 0;

    for(int i = 1; i <= n; i++){
        int l = pf[i]+1, r = sf[i]-1;
        if(r-l < 2)continue;

        if(i-l < r-i){
            for(int j = l; j < i; j++){
                int x = a[i]-a[j];
                if(id[x] > i && id[x] <= r)ans++;
            }
        }else{
            for(int j = r; j > i; j--){
                int x = a[i]-a[j];
                if(id[x] >= l && id[x] < i)ans++;
            }
        }
    }
    
    cout << ans << endl;

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

