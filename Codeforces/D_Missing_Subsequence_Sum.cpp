#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a;

    if(k == 1){
        a.push_back(2);a.push_back(3);

        for(int p = 4; p <= n; p*=2){
           a.push_back(p);
        }
        cout << a.size() << endl;
        for(auto x : a)cout << x <<' ';
        cout << endl;
        return;
    }

    int k1 = k;
    for(int i = 25; i >= 0; i--){
        if(k&(1<<i)){
            k1 = (1 << i);break;
        }
    }

  
    for(int i = 0; (1 << i) < k1; i++){
        a.push_back((1<<i));
    }

    int cur = k1-1;
    
    if(k-1 - (k1 - 1) >= 0)a.push_back(k-k1);
    a.push_back(k+1);
    a.push_back(k+2);

    k1 *= 2;
    while(a.size() < 25 && k1 <= n){
        a.push_back(k1);
        k1*=2;
    }
    for(int i = 3; i <= 10 && a.size() < 25; i++){
         a.push_back(k + i);
    }
    cout << a.size() << endl;
    for(auto x : a)cout << x <<' ';
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

