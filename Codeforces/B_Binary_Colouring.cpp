#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x; cin >> x;
    vector<int> a;
    if(x == 1){
        cout << "1\n1\n";return;
    }

    for(int i = 0; i < 35; i++){
        int cur = (x&(1ll<<i));
        if(cur == 0){
            if(i == 0){
                a.push_back(0);
                continue;
            }
            if((x&(1ll<<(i-1))) == 0)a.push_back(0);
            else if((x&(1ll<<(i+1))) != 0)a.push_back(-1);
            else a.push_back(1);
        }else{
            if((x&(1ll<<(i-1))) == 0)a.push_back(-1);
            else a.push_back(0);
        }
    }
    while(a.size() && a.back() == 0)a.pop_back();
    cout << a.size() << '\n';
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

