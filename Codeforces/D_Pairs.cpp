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
    set<int> st;
    for(int i = 1; i <= 2*n; i++){
        st.insert(i);
    }

    vector<int> b(n);

    for(int i = 0; i < n; i++){
        cin >> b[i];
        st.erase(b[i]);
    }

    set<int>  a = st;

    int l = 0, r = 0;

    for(int i = 0; i < n; i++){
        auto it = a.upper_bound(b[i]);
        if(it != a.end()){
            a.erase(it);
            r++;
        }else break;
    }

    a = st;

    for(int i = n-1; i >= 0; i--){
        auto it = a.lower_bound(b[i]);
        if(it != a.begin()){
            it--;
            l++;
            a.erase(it);
        }else break;
    }

    l = n - l;

    cout << r - l + 1 << endl;

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

