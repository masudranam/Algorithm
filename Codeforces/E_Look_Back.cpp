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
    vector<int> f(n+2),a(n+1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 2; i <= n; i++){
        if(a[i] == a[i-1])f[i] = f[i-1];
        else if(a[i] < a[i-1]){
            int x = a[i];
            while(x < a[i-1])x*=2,f[i]++;
            f[i] += f[i-1];
        }else{
            int x = a[i-1];
            while(f[i-1] > 0 && x <= a[i]){
                x*=2;
                f[i-1]--;
            }
            if(x <= a[i])f[i] = 0;
            else 
            f[i] = f[i-1]+1;             
        }
       // debug(f[i]);
        ans += f[i];
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

