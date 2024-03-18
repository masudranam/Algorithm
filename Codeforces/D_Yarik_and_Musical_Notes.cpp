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

int pw(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = (res*a)%M;
        a = (a*a) % M;
        b >>= 1;
    }
    return res;
}

int get(int a, int b){
    int x = pw(2,a), y = pw(2,b);
    if((pw(x,y) != pw(y,x))) return 0;
    return pw(x,y);
}
void solve(){
    int n;cin >> n;
    vector<int> a(n);
    int ans = 0;
    map<int,int> mp;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 2) a[i] = 1;
        ans += mp[a[i]];
        mp[a[i]]++;
    }
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

