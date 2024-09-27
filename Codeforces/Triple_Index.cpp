#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e6 + 10;
const int K = 450;

struct node{
    int l, r, i;
    bool operator < (const node &a)const{
       if(l / K == a.l / K){
        if((l / K) & 1) return r > a.r;
        return r < a.r;
       }
       return (l / K) < (a.l / K);
    }
};

int cur;
int cnt[N], f;

int get(int x){
    if(x < 3)return 0;
    return x * 1ll * (x - 1) * (x - 2) / 6;
}

void add(int i, int x){
   
    cur += (get(cnt[i] + x) - get(cnt[i]));
    cnt[i] += x;
    f++;
}


void solve(){
    int n, q; cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    node Q[q];

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r, l--,r--;
        Q[i] = {l, r, i};
    }

    sort(Q, Q + q);

    int l = 0, r = -1;
    vector<int> res(q);
    int mx = 0;
    for(auto it : Q){
        int L = it.l, R = it.r, id = it.i;
        
        while(r < R)add(a[++r], 1);
        while(l > L)add(a[--l], 1);
        while(l < L)add(a[l++], -1);
        while(r > R)add(a[r--], -1);
        res[id] = cur;
    }

    for(int i = 0; i < q; i++){
        cout << res[i] << '\n';
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
