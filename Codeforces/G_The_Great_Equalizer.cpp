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
    int n ;
    cin >> n;
    vector<int> a(n);
    multiset<int> s, d{0};

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    auto add = [&](int x){
        auto it = s.insert(x);
        if(it != s.begin()){
            d.insert(*it - *prev(it));
        }
        if(next(it) != s.end()){
            d.insert(*next(it) - *it);
        }

        if(it != s.begin() && next(it) != s.end()){
            d.erase(d.find(*next(it) - *prev(it)));
        }
    };


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

