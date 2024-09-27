#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int get(int x){
    return x * (x - 1) / 2;
}

void solve(){
    int n; cin >> n;
    map<int,int> mp;

    int res = n * (n - 1) / 2 , baki = n;
    pair<int,int> mx = {0, 0};

    for(int i = 0; i < n; i++){
        int id; cin >> id;
        int x; cin >> x;
        
        baki--;
        mp[x]++;
        
        if(x == mx.second){
            mx.first++;
            cout << res << ' ';
            continue;
        }
        

        if(mp[x] > mx.first){
            res -= get(mx.first + baki + 1);
            res += get(mx.first);
            res -= get(mp[x] - 1);
            res += get(mp[x] + baki);
            mx = {mp[x], x};
        }else{
            res -= get(mp[x] - 1);
            res += get(mp[x]);
            res -= get(mx.first + baki + 1);
            res += get(mx.first + baki);
        }
        cout << res <<' ';
    }
    cout << '\n';

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
