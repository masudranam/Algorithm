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

    int g = 0, mx = -M;
    multiset<int> st;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert(x);
        mx = max(mx,x);
    }

    if(n == 1){
        cout<<1<<endl;
        return;
    }

    for(auto x : st){
        g = __gcd(g, abs(x-mx));
    }

    int cnt = 0;
    for(auto x: st){
        cnt += abs(x-mx)/g;
    }

    int ans = M*M;
    for(int i = mx-g; ; i-=g){
        if(st.find(i) == st.end()){
            ans = min(ans,cnt + abs(mx-i)/g);
            break;
        }
    }
   ans = min(ans,cnt+n);
   cout<<ans<<endl;
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

