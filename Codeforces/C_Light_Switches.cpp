#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int k; cin >> k;

    vector<int> a(n);

    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    vector<pair<int,int>> v;

    for(int i = 0; i < n; i++){
        a[i] += 2*k * ((a.back() - a[i]) / (2*k));
        if(a[i] + k > a.back()){
            v.push_back({a[i], 1});
            v.push_back({a[i]+k, -1});
        }else{
            v.push_back({a[i] + 2*k, 1});
            v.push_back({a[i] + 3*k, -1});
        }
        if(i && a[i-1] + k == a[i]){
            cout <<-1 << '\n';return;
        }
    }
    sort(v.begin(),v.end());

    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        cnt += v[i].second;
        if(cnt == n){
            cout << v[i].first << '\n';
            return;
        }
    }
    cout << - 1 << '\n';
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