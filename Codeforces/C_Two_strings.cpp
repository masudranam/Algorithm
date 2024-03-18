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
    string a, b;
    cin >> a >> b;
    int n = sz(a), m = sz(b);
    vector<int> pf(m+2),sf(m+2);
    pf[0] = -1, sf[m+1] = n;

    vector<int> id[26];
    for(int i = 0; i < n; i++){
        id[a[i] - 'a'].push_back(i);
    }
    int cur = -1;

    for(int i = 1; i <= m; i++){
        int c = b[i-1]-'a';
        auto it = upper_bound(all(id[c]),cur);
        if(it == id[c].end()){
            pf[i] = n;
        }else pf[i] = *it;
        cur = pf[i];
    }

    if(pf[m] < n){
        cout<<b<<endl;
        return;
    }

    cur = n;
    for(int i = m; i >= 1; i--){
        int c = b[i-1]-'a';
        auto it = lower_bound(all(id[c]),cur);
        if(it == id[c].begin()){
            sf[i] = -1;
        }else{
            it--;
            sf[i] = *it; 
        }
        cur = sf[i];
    }


    string s = "-";

    int l = 1, r = m;
    while(r-l > 0){
        int mid = (l+r)/2;
        bool ok = 1;
        for(int i = mid; i <= m && ok; i++){
            if(pf[i-mid] < sf[i+1]){
                s = b.substr(0,i-mid) + b.substr(i);
                ok = 0;
            }
        }
        if(ok)l = mid+1;
        else r = mid;
    }

    cout<<s<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

