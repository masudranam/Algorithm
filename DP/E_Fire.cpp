#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e3 + 100;

int dp[110][N];
struct node{
    int t, d, p, id;
    bool operator <(const node &other)const{
        return  d < other.d;
    }
};

node a[N];
int n;
vector<int> p;

int get(int i, int cur){
    if(i == n){
        return 0;
    }
    int &ret = dp[i][cur];
    if(ret != -1) return ret;
    ret = get(i + 1, cur);

    if(cur + a[i].t < a[i].d){
        ret = max(ret, get(i + 1, cur + a[i].t) + a[i].p);
    }
    return ret;
}

void path(int i, int cur){
    if(i == n)return;
    if(cur + a[i].t < a[i].d  && get(i, cur) == get(i + 1, cur + a[i].t) + a[i].p){
        p.push_back(a[i].id);
        path(i + 1, cur + a[i].t);
    }else{
        path(i + 1, cur);
    }
}

void solve(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i].t >> a[i].d >> a[i].p;
        a[i].id = i + 1;
    }

    sort(a, a + n);
    memset(dp, -1, sizeof(dp));
    int res = get(0,0);
    path(0, 0);

    cout << res << '\n';
    cout << p.size() << '\n';
    for(auto x : p) cout << x << ' ';
    cout << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
// cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}