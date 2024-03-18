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
    int n, c; 
    cin >> n >> c;
    set<int>st;
    vector<int> a(n+1);

 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 1)st.insert(i);        
    }
    
    int cur = a[1];

    while(sz(st)){
        vector<int> v;

        for(auto x: st){
            if(cur+a[x] >= x*c){
                cur+=a[x];
                v.push_back(x);
            }
        }
        if(sz(v) == 0){
            cout<<"No\n";return;
        }
        for(auto x: v)st.erase(x);
    }
    cout<<"Yes\n";
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

