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
    int k ; cin >> k;

    set<int> st;
    vector<int> a(n),p(n+2);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }

    int cur = 0;
    for(int i = 0; i <= n; i++){
        if(st.find(i) == st.end())cur = i;
    }
    p[cur] = a[0];
    for(int i = 0; i+1< n; i++){
        p[a[i]] = a[i+1];
    }
    p[a[n-1]] = cur;


    k--;
    k = k%(n+1);
    if(k)k = (n+1)-k;

    while(k--){
        cur = p[cur];
    }
    //debug(p[2]);
    for(int i = 0; i < n; i++){
        cout<<cur<<" \n"[i==n-1];
        cur = p[cur];
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

