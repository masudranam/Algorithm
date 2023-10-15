//https://atcoder.jp/contests/abc322/tasks/abc322_f
#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 5e5 + 10;


struct node{
    struct data{
        int l, r, s;
        bool all;
    }_data[2];
    bool flip;

    node operator+(const node & o){
        node ret;
        ret.flip = 0;
        for(int i = 0; i < 2; i++){
            const auto &L = _data[i], R = o._data[i];
            ret._data[i].s = max({L.s,R.s,L.r+R.l});
            ret._data[i].l = L.l;
            ret._data[i].r = R.r;
            if(L.all)ret._data[i].l = L.r+R.l;
            if(R.all)ret._data[i].r = L.r + R.r;
            ret._data[i].all = (L.all && R.all);
        }
        return ret;
    }
    void swap_data(){swap(_data[0],_data[1]);}
    int get(){return _data[1].s;}
}st[N<<2];


void build(int i, int l, int r, const string &s){
    if(l == r){
        st[i].flip = 0;
        for(int j = 0; j < 2; j++){
            auto &data = st[i]._data[j];
            data.l = data.r = data.all = data.s = (s[l-1] == '0'+j);
        }
        return;
    }
    int m = (l+r)>>1;
    build(2*i,l,m,s);
    build(2*i+1,m+1,r,s);
    st[i] = st[2*i] + st[2*i+1];
}

void push(int i){
    if(st[i].flip){
        st[2*i].flip^=1;
        st[2*i].swap_data();
        st[2*i+1].flip^=1;
        st[2*i+1].swap_data();
        st[i].flip = 0;
    }
}

void upd(int i, int l, int r, int l1, int r1){
    if(l1 <= l && r <= r1){
        st[i].flip ^= 1;
        st[i].swap_data();
        return;
    }
    push(i);
    int m = (l+r) >> 1;
    if(l1 <= m)upd(2*i,l,m,l1,r1);
    if(r1 > m)upd(2*i+1,m+1,r,l1,r1);
    st[i] = st[2*i]+st[2*i+1];
}

node qry(int i, int l, int r, int l1, int r1){
    if(l1 <= l && r <= r1){
        return st[i];
    }
    push(i);
    int m = (l+r)>>1;
    node L, R;
    if(l1 <= m)L = qry(2*i,l,m,l1,r1);
    if(r1 > m)R = qry(2*i+1,m+1,r,l1,r1);

    if(l1 > m)return R;
    else if(r1 <= m)return L;
    else return L+R;
}

void solve(){
    int n, q;
    cin >> n >> q;
    string s; cin >> s;
    build(1,1,n,s);

    while(q--){
        int c, l, r;
        cin >> c >> l >> r;
        if(c == 1)upd(1,1,n,l,r);
        else{
            auto ans = qry(1,1,n,l,r);
            cout<<ans.get()<<endl;
        }
    }
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

