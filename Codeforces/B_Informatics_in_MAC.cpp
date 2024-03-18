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
    for(auto &x : a) cin >> x;

    vector<int> sf(n);
    set<int> st;
    int mex = 0;
    for(int i = n-1; i >= 0; i--){
        st.insert(a[i]);
        while(st.find(mex) != st.end())mex++;
        sf[i] = mex;
    }
    st.clear();
    mex = 0;
    for(int i = 0; i + 1 < n; i++){
        st.insert(a[i]);
        while(st.find(mex) != st.end())mex++;
        if(mex == sf[i+1]){
            cout <<2<<endl;
            cout <<1 <<' '<<i+1 << endl;
            cout << i+2 <<' '<<n<<endl;
            return;
        }
    }
    cout << -1 << endl;

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

