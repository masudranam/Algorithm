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
vector<int>b(n),ps(n+1),ss(n+1);
vector<ar<int,2>> a(n);
for(int i = 0; i < n; i++){
    cin >> a[i][0];
    a[i][1] = i;
}
if(n == 1){
    cout <<1 << endl;
    return;
}

sort(all(a));
int cur = 0;
for(int i = 1; i <n; i++){
    ps[i] = ps[i-1] + (i)*(a[i][0]-a[i-1][0]+1)-(i-1);
}

for(int i = n-2; i >= 0; i--){
    ss[i] = (ss[i+1]) + (n-i-1)*(a[i+1][0]-a[i][0]+1)-(n-i-1-1);
}

vector<int> ans(n);

for(int i = 0; i < n; i++){
    ans[a[i][1]] = ps[i]+ss[i]+1;
}
print(ans);




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

