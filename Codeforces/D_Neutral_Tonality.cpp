
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
   int n, m;
   cin >> n >> m;

   vector<int> a(n), b(m);

   for(int i = 0; i < n; i++){
    cin >> a[i];
   }
   for(int i = 0; i < m; i++){
    cin >> b[i];
   }
   sort(all(b));

   vector<int> ans;
   int j = m-1;
   for(int i = 0; i < n; i++){
    while(j >= 0 && b[j] >= a[i])ans.push_back(b[j]),j--;
    ans.push_back(a[i]);
   }
   while(j >= 0)ans.push_back(b[j]),j--;
   print(ans);

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

