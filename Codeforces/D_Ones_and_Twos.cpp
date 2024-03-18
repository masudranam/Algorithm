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
const int N = 2e5 + 10;

int n, q;

struct node {
    int mn,s,mx,lz;
} st[1<<20]; // for 1e6 -> 22


struct ST {
    void upd(int l1,int x,int i=1,int l2=0,int r2=n-1) {
        if(l2==r2) {
            st[i].mx=x;
            return;
        }
        int m2=(l2+r2)/2;
        if(l1<=m2) upd(l1,x,2*i,l2,m2);
        else upd(l1,x,2*i+1,m2+1,r2);
        st[i].mx=(st[2*i].mx+st[2*i+1].mx);
    }

    int qry(int l1,int r1,int i=1,int l2=0,int r2=n-1) {
        if(l2>=l1&&r2<=r1)
            return st[i].mx;
        if(l2 > r1 || r2 < l1)return 0; //This line is crazy
        int m2=(l2+r2)/2;
        return ((l1<=m2?qry(l1,r1,2*i,l2,m2):0)+(m2<r1?qry(l1,r1,2*i+1,m2+1,r2):0));
    }
};

void solve(){
    cin >> n >> q;
    vector<int> a(n);
    int cur = 0;
    ST st;
    set<int> one,two;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        cur += a[i];
        if(a[i] == 1)one.insert(i);
        else two.insert(i);
        st.upd(i,a[i]);
    }


    while(q--){
        int x; cin >> x;
        if(x == 2){
            int id, k;
            cin >> id >> k;
            id--;
            if(a[id] == 1)one.erase(id);
            else two.erase(id);

            cur -= a[id];
            cur += k;
            a[id] = k;
            if(k == 1)one.insert(id);
            else two.insert(id);
            st.upd(id,k);
            continue;
        }

        int s; cin >> s;
        if(cur < s){
            cout<<"NO\n";continue;
        }

        int l = 0, r = n-1;
        while(r-l > 0){
            int m = (l+r)/2;
            if(st.qry(0,m) >= s)r = m;
            else l = m+1;
        }

        if(st.qry(0,l) == s){
            cout<<"YES\n";continue;
        }

        auto it = one.lower_bound(l);
        int pos = l;
        int cnt = 50;
        bool f = 0;
        while(it != one.end() && cnt--){
            l = 0, r = *it;
            while(r-l > 0){
                int m = (l+r)/2;
                if(st.qry(l,*it) > s)l = m+1;
                else r = m;
            }
            if(st.qry(l,*it) == s){
                cout<<"YES\n";f = 1;break;
            }
            it++;
        }
        if(f)continue;
        it = two.lower_bound(pos);
        cnt = 50;
        f = 0;
         while(it != one.end() && cnt--){
            l = 0, r = *it;
            while(r-l > 0){
                int m = (l+r)/2;
                if(st.qry(l,*it) > s)l = m+1;
                else r = m;
            }
            if(st.qry(l,*it) == s){
                cout<<"YES\n";f = 1;break;
            }
            it++;
        }
        if(f)continue;
        cout<<"NO\n";
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

