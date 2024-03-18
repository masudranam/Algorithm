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
string s, t;
cin >> s >> t;
int ans = 0;
while(sz(s) < sz(t))s = s + s, ans++;

for(int i = 0; i < 5; i++){
   if(s.find(t) != string::npos){
      cout<<ans<<endl;return;
   }
   s = s + s;
   ans++;
}
cout<<-1<<endl;


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

