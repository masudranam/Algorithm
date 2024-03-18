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
multiset<int> st;
vector<int> a(n);
for(int i = 0; i < n; i++){
    cin >> a[i];
    st.insert(a[i]);
}

int ans = 0;
for(int i = n-1; i> 0; i--){
    if(a[i-1] > a[i]){
        ans = *st.rbegin();
        break;
    }
    st.erase(st.find(a[i]));
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

