#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
//#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int a[N], n;
vector<pair<int,int>> g[N];

bool ok(int x){
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
         for(auto it : g[i]){
            if(it.second)
            pq.push({-it.first, it.second});
         }
        if(!pq.empty() && -pq.top().first < i) return false;
        int cur = x;
        while(cur > 0 && !pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int mn = min(cur, p.second);
            cur -= mn; p.second -= mn;
            if(p.second)pq.push(p);
        }
    }
    return pq.empty();
}

 

void solve(){
    cin >> n;
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        
    }

    for(int i = 0; i < n; i++){
        int d; cin >> d;
        int l = max(0, i - d);
        int r = min(n-1, i + d);
        g[l].push_back({r, a[i]});
    }

    

    int l = 0 , r = M;
    while(r - l > 0){
        int m = (l + r) / 2;
        if(ok(m)) r = m;
        else l = m + 1;
    }
    cout << l << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}