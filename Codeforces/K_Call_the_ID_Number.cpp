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
vector<int> a(n+1),b(n+1);
for(int i = 1; i <= n; i++){
    cin >> a[i];
}

for(int i = 1; i<=n; i++){
    if(!b[i]){
        b[a[i]] = 1;
    }
}
vector<int> ans;
for(int i = 1; i <= n; i++){
    if(!b[i])ans.push_back(i);
}

sort(all(ans));
cout<<sz(ans)<<endl;
print(ans);
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

