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

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n <= 2){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 1)cout<<3<<' ';
        else if(a[i] == 3)cout << 1 <<' ';
        else cout << a[i] <<' ';
    }
    cout << endl;
    
    // vector<pair<int,int>> p;

    // for(int i = 0; i < n; i++){
    //     int x; cin >> x;
    //     p.push_back({x,i});
    // }

    // if(n <= 2){
    //     cout << -1 << endl;
    //     return;
    // }

    // sort(all(p));

    // vector<int> ans(n);

    // for(int i = 0, j = n; i < n; i++){
    //     ans[p[i].second] = j--;
    // }
    

    // for(auto x : ans)cout <<x<<' ';
    // cout << endl;
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

