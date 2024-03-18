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

int f(int x){
    int res = x/3;
    if(x%3 == 1)res++;
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    int sum = 0,odd = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        odd += (a[i]%2 == 1);
        if(i == 0)cout<< sum <<' ';
        else 
        cout << sum - f(odd) <<' ';
    }
    cout << endl;
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

