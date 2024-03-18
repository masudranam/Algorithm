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
    int n; 
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)cin >>a[i];

    vector<int> b;

    b.push_back(a[1]);
    for(int i = 2; i <= n; i++){
        if(a[i] >= a[i-1])b.push_back(a[i]);
        else b.push_back(1),b.push_back(a[i]);
    }
    cout<<sz(b)<<endl;
    print(b);

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

