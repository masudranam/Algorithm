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
vector<int> a(n),b,c;
for(int i = 0; i < n; i++)cin >> a[i];

sort(all(a));

for(int i = n-1; i >= 0; i--){
    if(a[i] == a[n-1])c.push_back(a[i]);
    else b.push_back(a[i]);
}

if(sz(b) == n || sz(c) == n)cout<<-1 << endl;
else{
    cout<<sz(b)<<' '<<sz(c)<<endl;
    print(b);
    print(c);
}

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

