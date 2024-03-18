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

int f1(int x){
    int y = sqrt(x);
    if(x == 0) return 0;
    
    return min((y+1)*(y+1)-x, x - y*y);
}

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    int zero = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        zero += a[i] == 0;

        a[i] = f1(a[i]);
    }

    sort(all(a));

    if(a[n/2] == 0){
        int ans = 0;
        for(int i = n/2; i < n; i++)ans += a[i]==0;
        ans += max(0ll,zero-n/2);
        cout<<ans<<endl;
    }else{
        int ans = 0;
        for(int i = 0; i < n/2; i++){
            ans += a[i];
        }
        cout<<ans<<endl;
    }
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

