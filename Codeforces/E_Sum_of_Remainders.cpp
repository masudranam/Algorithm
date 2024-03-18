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

int f(int l, int r, int d){
    int res = (r-l+1)%M * (r+l)%M;
    res = (res%M * d%M);
    res = (res*pw(2,M-2))%M;
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> d;

    for(int i = 1; i*i <= n; i++){
        d.push_back(i);
        if(n/i != i)d.push_back(n/i);
    }

    d.push_back(0);
    sort(all(d));

    int ans = (n%M)*(m%M);
    ans = (ans % M);


    for(int i = 1; i < sz(d); i++){
        int l = d[i-1] + 1, r = min(d[i],m);
        if(l > m)break;
        ans = (ans%M - f(l,r,n/l)%M + M)%M;;
    }
    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

