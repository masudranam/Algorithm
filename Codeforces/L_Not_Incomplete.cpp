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

int x,y,z,n;
cin >> x >> y >> z >> n;
double t = x*y;
int tot = 0;
while(true){
    double c = t*0.6;
    if(tot*1.0 >= c)break;
    tot++;
}

tot -= n;

int baki = x - z;

if(baki*y < tot){
    cout<<"No\n";return;
}

vector<int> ans;

while(tot > 0){
    if(tot >= y)ans.push_back(y),tot-=y;
    else ans.push_back(tot),tot = 0;
}
while(sz(ans) < baki)ans.push_back(0);


sort(all(ans));
cout<<"Yes\n";
print(ans);

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

