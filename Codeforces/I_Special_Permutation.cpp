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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> l, r;
    l.push_back(a);
     set<int> st;

    for(int i = 1; i <= n; i++)st.insert(i);
   
    st.erase(a);

    for(int i = n; i >= 1 && sz(l)<n/2; i--){
        if(i == b)continue;
        if(st.find(i) != st.end()){
        l.push_back(i);
        st.erase(i);
        }
    }

    for(auto i: st)r.push_back(i);
    if(sz(l) != sz(r) || l.back() < a || r.back() > b){
        cout<<-1<<endl;return;
    }
    for(auto i: l)cout<<i<<' ';
    for(auto i: r)cout<<i<<' ';
    cout<<endl;
    
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

