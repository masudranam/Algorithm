#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
<<<<<<< HEAD
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;


int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    set<int> st, d;
    for(int i = 0; i < n; i++){
        if(a.back() % a[i]){
            cout << n << '\n';
            return;
        }
        st.insert(a[i]);
    }

    for(int i = 1; i * i <= a.back(); i++){
        if(a.back() % i)continue;
        d.insert(i);
        d.insert(a.back() / i);
    }

    int ans = 0;
    for(auto d1 : d){
        if(st.find(d1) != st.end())continue;
        int l = 1, cnt = 0;
        for(int i = 0; i < n; i++){
            if(d1 % a[i] == 0){
                cnt++, l = lcm(a[i], l);
            }
        }
         ans = max(ans, cnt);
    }

    cout << ans << '\n';
=======

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n;
map<int,int> dp[2010],b;
set<int> p;
vector<int> a;

int upd(int x, int y){
    for(auto p1 : p){
        int c1 = 0,c2 = 0;
        while(x%p1 == 0)c1++, x/=p1;
        while(y%p1 == 0) y/=p1, c2++;
        for(int i = 0; i < max(c1,c2); i++) y *= p1;
    }
    return y;
}

int get(int i, int val){
    if(i == n){
        if(b.find(val) != b.end())return -M;
        return 0;
    }

    if(dp[i].find(val) != dp[i].end())return dp[i][val];
    int res = get(i+1,upd(a[i],val));
    res = max(res, get(i+1, val));
    return dp[i][val] = res;
}

int lc(int a, int b){
    return a*b/__gcd(a,b);
}


void solve(){
    cin >> n;
    for(int i = 0; i <= n; i++)dp[i].clear();
    a.clear();p.clear();b.clear();


    int cnt = 0, mx = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 1)cnt++;
        else a.push_back(x), b[x] = 1;
        mx  = max(mx, x);
    }
    int l = 1;
    n = a.size();

    for(int i = 0; i < a.size(); i++){
        l = lc(l,a[i]);
        if(l > mx){
            cout << n + cnt << '\n';
            return;
        }
    }
    
    for(int i = 0; i < n; i++){
        int x = a[i];
        for(int j = 2; j*j <= x; j++){
            while(x%j == 0)p.insert(j), x/=j;
        }
        if(x > 1)p.insert(x);
    }

    int res = cnt + get(0,1);

    cout << max(0ll, res) << '\n';


>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
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
<<<<<<< HEAD
=======

>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
