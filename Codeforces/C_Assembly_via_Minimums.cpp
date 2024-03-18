#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;

    int nn = n*(n-1)/2;
    vector<int> a(nn);

    for(int i = 0; i <nn ; i++){
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));

    vector<int> ans;

    int baki = n-1;

    while(sz(a)){
        int cur = a.back();
        
        int cnt = 0;
        while(sz(a) && (a.back() == cur))a.pop_back(),cnt++;
        while(cnt > 0){
            ans.push_back(cur);
            cnt -= baki;
            baki--;
        }
    }

    while(sz(ans) < n){
        ans.push_back(M);
    }
    print(ans);

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

