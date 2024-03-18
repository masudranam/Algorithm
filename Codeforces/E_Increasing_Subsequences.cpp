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
    int X; cin >> X;
    vector<int> a{0};

    while(true){
        int x = sz(a) + 1;
        if((1ll << x) <= X)a.push_back(a.back()+1);
        else{
            X -= (1ll << (x-1));
            break;
        }
    }

    for(int i = 60; i >= 0; i--){
        if(X&(1ll<<i)){
            a.push_back(a[i]);
        }
    }
    cout << sz(a) << endl;
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

