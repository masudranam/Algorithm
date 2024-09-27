#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
<<<<<<< HEAD
 
=======

>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x; cin >> x;
<<<<<<< HEAD
    vector<int> a(32);

    for(int i = 0; i < 32; i++){
        a[i] = (x>>i)&1;
        if(i && a[i] != 0 && a[i-1] != 0){
            a[i] = 0;
            x += (1ll<<i)/2;
            a[i-1] = -1;
        }
    }
    cout << 32 << '\n';
    for(int i = 0; i < 32; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
=======
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
>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
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
<<<<<<< HEAD
=======

>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
