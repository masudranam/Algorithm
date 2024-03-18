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
    int n, m;
    cin >> n >> m;

    vector<int> a(n-1);
    multiset<int> b;

    for(int i = 0; i + 1 < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b.insert(x);
    }

    sort(all(a));
    int cnt = 0;

    for(int i = 0; i +1 < n; i++){
        auto it = b.upper_bound(a[i]);
        if(it != b.end()){
            b.erase(b.find(*it));
            cnt++;
        }
    }
    //print(b);
    //debug(cnt);
    int ans = cnt*m + min(m,*b.rbegin()-1);
    cout<<(n*m - ans)<<endl;
    
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

