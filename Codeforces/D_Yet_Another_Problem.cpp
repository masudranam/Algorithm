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
    vector<int> a(n+1),ps(n+1);

    map<int,vector<int>>mp,mp1;


    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ps[i] = a[i];
        ps[i] += ps[i-1];
        a[i] ^= a[i-1];
        if(i%2)mp1[a[i]].push_back(i);
        else mp[a[i]].push_back(i);
    }

    while(q--){
        int l, r; cin >> l >> r;
        if(a[r]^a[l-1]){
            cout<<-1<<endl;
        }else{
            if(ps[r]-ps[l-1] == 0)cout<<0<<endl;
            else if((r-l+1)&1)cout<<1<<endl;
            else{
                if(ps[l]-ps[l-1] == 0 || ps[r]-ps[r-1] == 0){
                    cout<<1<<endl;
                    continue;
                }
                
                if(l%2){
                    auto &v = mp1[a[l-1]];
                    auto it = lower_bound(all(v),l);
                    if(it == v.end() || *it >= r)cout<<-1<<endl;
                    else cout<<2<<endl;
                }else{
                    auto &v = mp[a[l-1]];
                    auto it = lower_bound(all(v),l);
                    if(it == v.end() || *it >= r)cout<<-1<<endl;
                    else cout<<2<<endl;
                }
            }
        }
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

