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
    int n, q;
    cin >> n >> q;

    string s; cin >> s;

    int v[n+1], h[n+1], x = 0, y = 0;
    set<ar<int,3>> a, b;
    v[0] = h[0] = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'R')x++;
        else if(s[i] == 'L')x--;
        else if(s[i] == 'U')y++;
        else y--;
       // cout << x <<' ' << y << endl;
        v[i+1] = y, h[i+1] = x;
        a.insert({x,y,i+1});
    }

    int rh[n+2], rv[n+2];
    x = 0, y = 0, rh[n+1] = 0, rv[n+1] = 0;

    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'R')x++;
        else if(s[i] == 'L')x--;
        else if(s[i] == 'U')y++;
        else y--;
        rh[i+1] = x, rv[i+1] = y;
        b.insert({x,y,i+1});
    }

    a.insert({0,0,0});

    while(q--){
        int l, r;
        cin >> x >> y >> l >> r;
        auto it = a.lower_bound({x,y,0});
        ar<int,3> tmp;

        if(it != a.end()){
            tmp = *it;
            if(tmp[2] < l && tmp[0] == x && tmp[1] == y){
              //  debug(tmp[2]);
                cout<<"YES\n";
                continue;
            }
        }

        it = a.lower_bound({x,y,r});
        if(it != a.end()){
            tmp = *it;
            if(tmp[2] > r && tmp[0] == x && tmp[1] == y){
                cout<<"YES\n";
                continue;
            }
        }

        x = x - h[l-1] + rh[r+1];
        y = y - v[l-1] + rv[r+1];
        it = b.lower_bound({x,y,l});

        if(it != b.end()){
            tmp = *it;
            if(tmp[2] <= r  && tmp[2] >= l && tmp[0] == x && tmp[1] == y){
                cout<<"YES\n";
                continue;
            }
        }
        cout<<"NO\n"; 
    }



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
 