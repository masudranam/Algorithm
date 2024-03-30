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
    int l; cin >> l;
    vector<pair<int,int> > a(n);


    for(int i = 0; i < n; i++){
        cin >> a[i].second >> a[i].first;
    }
    sort(all(a));

    int ans = 0;
    for(int i = 0; i < n; i++){
        priority_queue<int> q;
        int s = 0;
        for(int j = i; j < n; j++){
            s += a[j].second;
            q.push(a[j].second);
            while(sz(q) && s + a[j].first - a[i].first > l){
                s -= q.top();
                q.pop();
            }
            ans = max(ans,sz(q));
        }
    }

    cout << ans << endl;
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
