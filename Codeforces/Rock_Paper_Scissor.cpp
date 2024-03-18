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
    string a, b;
    cin >> a >> b;
    int one = 0, two = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 'R' && b[i] == 'S')one++;
        if(a[i] == 'S' && b[i] == 'P')one++;
        if(a[i] == 'P' && b[i] == 'R')one++;

        if(a[i] == 'S' && b[i] == 'R')two++;
        if(a[i] == 'P' && b[i] == 'S')two++;
        if(a[i] == 'R' && b[i] == 'P')two++;
    }
    
    cout<<max(0ll,(two-one+2)/2)<<endl;
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

