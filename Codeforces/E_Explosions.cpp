#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int get(int x){
    return x * (x + 1) / 2;
}

int get(int len , int sum, int x){
     int res = get(x) - get(x - len);
    return sum - res;
}

vector<int> get(vector<int> a){
    int n = a.size() - 1;
    vector<int> dp(n+1), prv(n+1), ps(n+1);

    for(int i = 1; i <= n; i++){
        ps[i] = ps[i-1] + a[i];
    }

    stack<pair<int,int>> stk;

    for(int i = n; i >= 1; i--){
        while(stk.size() && a[i] <= stk.top().first - (stk.top().second - i)){
            prv[stk.top().second] = i;
            stk.pop();
        }
        stk.push({a[i], i});
    }
    while(stk.size()){
        prv[stk.top().second] = 0;
        stk.pop();
    }

    for(int i = 1; i <= n; i++){
        int j = prv[i];
        int k = max(1ll, i - (a[i] - 1));
        if(k <= j){
            dp[i] += get(i - j,(ps[i] - ps[j]), a[i]);
            dp[i] += dp[j];
        }else{
            dp[i] += ps[k-1];
            dp[i] += get(i - k + 1, ps[i] - ps[k-1], a[i]);
        }
    }
    return dp;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n+2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    vector<int> dp = get(a);
    reverse(a.begin(), a.end());
    vector<int> tp = get(a);
    reverse(tp.begin(), tp.end());
    reverse(a.begin(), a.end());

    int res = N*M;
    for(int i = 1; i <= n; i++){
        res = min(res, dp[i] + tp[i] + a[i]);
    }
    cout << res << '\n';
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