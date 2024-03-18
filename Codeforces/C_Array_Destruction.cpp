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
const int N = 1e6 + 10;

int a[N],n;
vector<ar<int,2>> ans;

bool ok(int x){
    multiset<int> st;

    for(int i = 0; i + 1 < n; i++){
        if(i == x)continue;
        st.insert(a[i]);
    }
    ans.clear();
// print(st);

    ans.push_back({a[x],a[n-1]});
    int cur = a[n-1];
    while(sz(st) > 1){
        int big = *(st.rbegin());
        int small = cur - big;
        st.erase(--st.end());
        if(st.find(small) == st.end())return false;
        st.erase(st.find(small));
        ans.push_back({small,big});
        cur = max(big,small);
    }
  return true;
}

void solve(){
    cin >> n;
    n = 2*n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0; i + 1 < n; i++){
        if(ok(i)){
            cout<<"YES\n";
            cout<<a[i]+a[n-1]<<endl;
            for(auto it: ans){
                cout<<it[0]<<' '<<it[1]<<endl;
            }
            return;
        }
    }
    cout<<"NO\n";
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

