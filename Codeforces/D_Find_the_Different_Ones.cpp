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
    map<int,vector<int>> mp;
    vector<pair<int,int>> a;

    vector<int> b(n+2);

    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    int cur = 1;
    for(int i = n - 1; i >= 1; i--){
        if(b[i] == b[i+1])cur++;
        else{
            cur = 1;
        }
        a.push_back({i,i+cur});
    }

    sort(all(a));
    

    int q; cin >> q;

    while(q--){
        int l, r; cin >> l >> r;
        pair<int,int> p{l,0};
        auto it = lower_bound(all(a),p);
        if(it != a.end()){
            if((*it).second <= r){
                cout <<(*it).first<<' '<<(*it).second<<endl;
            }else{
                cout << - 1 <<' '<<-1 << endl;
            }
        }else{
            cout<<-1<<' '<<-1 << endl;
        }
    }
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

