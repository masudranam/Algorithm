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
    vector<int> a(n);
    multiset<int> st;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }

    int cnt = 0, cur = 0;
    while(st.upper_bound(cnt) != st.end()){
        auto it = st.upper_bound(cnt++);
        cur += *it;
        st.erase(it);
    }

    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--){
        ans[i] = cur - cnt*(cnt+1)/2;
        cur -= a[i];

        auto it = st.lower_bound(a[i]);
        if(it == st.end())cnt--;
        else{
            cur += *it;
            st.erase(it);
        }
    }   

    for(int i = 0; i < n; i++){
        cout << ans[i] <<" \n"[i == n-1];
    }
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

