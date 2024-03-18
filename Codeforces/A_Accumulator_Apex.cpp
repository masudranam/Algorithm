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
    int x, k;
    cin >> x >> k;

    vector<pair<int,int>> v;

    for(int i = 0; i < k; i++){
        int l; cin >> l;
        int mn = 0, cur = 0,last = 0;

        for(int j = 0; j < l; j++){
            int val; cin >> val;
            cur += val;
            if(cur > last){
                v.push_back({-mn,cur - last});
                last = cur;
            }
            mn = min(cur,mn);
        }
    }

    sort(all(v));


    for(int i = 0; i < sz(v); i++){
        if(v[i].first <= x){
            x += v[i].second;
        }else break;
    }

    cout << x << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

