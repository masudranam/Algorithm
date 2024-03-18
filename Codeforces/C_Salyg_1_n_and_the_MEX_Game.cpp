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
for(int i = 0; i < n; i++){
    int x; cin >> x;
    st.insert(x);
}

int cur = 0;
while(st.find(cur) != st.end())cur++;
int y ;

while(true){
    cout<<cur<<endl;
    st.insert(cur);
    cout.flush();
    cin >> y;
    if(y == -1){
        break;
    }
    if(y >= 0){
        st.erase(st.find(y));
        cur = y;
    }
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

