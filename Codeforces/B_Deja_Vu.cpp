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
 vector<int> a(n);
 for(int i = 0; i < n; i++){
    cin >> a[i];
 }

 vector<int> b;
 int mn = M;
 for(int i=0; i < m; i++){
    int x;cin>> x;
    if(mn <= x)continue;
    b.push_back((1<<x));
    mn = min(mn,x);
 }

 sort(all(b));
 m = sz(b);
 vector<int> ps(m);

 for(int i = 0; i < m; i++){
    if(i)ps[i] = ps[i-1]+b[i];
    else ps[i] = b[i];
 }

 for(int i = 0; i < n; i++){
    int x = 0;
    for(int j = 0; j < 30; j++){
        if(a[i]&(1<<j)){
            x = (1<<j);break;
        }
    }
    auto it = upper_bound(all(b),x)-b.begin();
    it--;
    if(it < m && a[i]%b[it] == 0){
        a[i] += (ps[it]/2);
    }
 }
 print(a);

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

