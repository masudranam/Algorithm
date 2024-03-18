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

int n ;
int a[N], b[N];

int get(int val, int x){
    int l = 0, r = x;
    while(r-l > 0){
        int m = (l+r)/2;
        if(2*m+(x-m) >= val)r = m;
        else l = m+1;
    }
    return r;
}

bool ok(int x){
    int cur = 0;
    for(int i = 0; i < n; i++)b[i] = 0;

    for(int i = 0; i+1< n; i++){
        b[i] += a[i];
        if(2*x < b[i])return false;
        int y = get(b[i],x);
        b[i+1] += 2*y;
    }
    b[n-1] += a[n-1];
    return b[n-1] <= x;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = 0, r = N;
    while(r-l > 0){
        int m = (l+r)/2;
        if(ok(m))r = m;
        else l = m+1;
    }
    cout<<l<<endl;
    
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

