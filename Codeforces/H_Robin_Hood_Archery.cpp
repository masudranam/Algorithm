#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e6 + 10;
const int K = 500;

struct node{
    int l, r, i;
    bool operator < (const node &a)const{
        if(l / K == a.l / K){
            return r < a.r;
        }
        return (l / K) < (a.l / K);
    }
};

int a[N], cnt[N], odd;

void add(int i, int x){
    cnt[a[i]] += (x * 1);
    if(cnt[a[i]] % 2)odd++;
    else odd--;
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i], cnt[a[i]] = 0;
    }

    node Q[q];

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l--, r--;
        Q[i] = {l, r, i};
    }
    sort(Q, Q + q);
    vector<int> res(q);
    int l = 0, r = -1;
    odd = 0;

    for(auto i : Q){
        int L = i.l, R = i.r;
        while(r < R)add(++r, 1);
        while(l > L)add(--l, 1);
        while(l < L)add(l++, -1);
        while(r > R)add(r--, -1);
        if(odd)res[i.i] = 1;
    }

    for(int i = 0; i < q; i++){
        if(res[i]) cout << "NO\n";
        else cout << "YES\n";
    }
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