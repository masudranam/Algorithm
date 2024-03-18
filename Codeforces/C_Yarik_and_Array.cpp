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

int get(vector<int> a){
    int n = sz(a);
    int ans = -M*M;
    int mn = 0, cur = 0;
    for(int i = 0; i < n; i++){
        cur += a[i];
        ans = max(ans,cur-mn);
        mn = min(cur,mn);
        ans = max(ans,a[i]);
    }
    //print(a);
   // cout<<ans<<endl;
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a;
    int ans = -M*M;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(a.empty() || (abs(a.back())%2 != abs(x)%2))a.push_back(x);
        else {
            ans = max(ans,get(a));
            a.clear();
            a.push_back(x);
        }
    }
    ans = max(ans,get(a));
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

