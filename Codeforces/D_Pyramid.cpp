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
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> left(n),right(n);
    deque<int> d;

    for(int i = 0; i < n; i++){
        if(sz(d)+1 <= a[i])d.push_back(a[i]);
        else{
            while(sz(d)+1 > a[i])d.pop_front();
        }
        left[i] = sz(d);
    }
    d.clear();
    for(int i = n-1; i >= 0; i--){
        if(sz(d)+1 <= a[i])d.push_back(a[i]);
        else{
            while(sz(d)+1 > a[i])d.pop_front();
        }
        right[i] = sz(d);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, min(left[i],right[i]));
    }
    
    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

