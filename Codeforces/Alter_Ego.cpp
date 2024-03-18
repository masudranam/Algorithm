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
    vector<int> a, b;
    for(int i = 0;i < n; i++){
        int x; cin >> x;
        if(x&1)a.push_back(x);
        else b.push_back(x);
    }
    sort(all(a));
    sort(all(b));

    if(sz(a)%2 || sz(b)%2){
        cout<<-1<<endl;
        return;
    }

    vector<int> ans(n);

    int l = 0, r = n/2;
    for(int i = 0, j = sz(a)/2; i < sz(a)/2; i++,j++){
        int x = (a[i]+a[j])/2, y = a[j]-x;
        ans[l] = x, ans[r]=y;
        l++,r++;
    }

    for(int i = 0, j = sz(b)/2; i < sz(b)/2; i++,j++){
        int x = (b[i]+b[j])/2, y = b[j]-x;
        ans[l] = x, ans[r] = y;
        l++,r++;
    }
    for(int i = 0; i < n; i++)cout<<ans[i]<<' ';
    cout<<endl;
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

