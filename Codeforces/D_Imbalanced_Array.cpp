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

int get(vector<int> a){
    int n = sz(a); 
    vector<int> L(n+2,-1),R(n+2,n);
    vector<int> stk;

    for(int i = 0; i < n; i++){
        while(sz(stk) && a[stk.back()] > a[i]){
            stk.pop_back();
        }
        if(sz(stk))L[i] = stk.back();
        stk.push_back(i);
    }
    stk.clear();
    for(int i = n-1; i >= 0; i--){
        while(sz(stk) && a[stk.back()] >= a[i]){
            stk.pop_back();
        }
        if(sz(stk)) R[i] = stk.back();
        stk.push_back(i);
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += a[i]*((i-L[i])*(R[i]-i));
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a)cin >> x;

    int mn = get(a);
    for(auto &x: a) x = -x;
    int mx = -get(a);
   cout<<mx-mn<<endl;
 

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

