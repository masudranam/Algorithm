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

struct P{
    int l, r, i;
};

bool cmp(P a, P b){
   return (a.r-a.l) > (b.r - b.l);
}

void solve(){
    int n; cin >> n;
    P p[n];

    set<int> st;

    for(int i = 0; i < n; i++){
        cin >> p[i].l >> p[i].r;
        p[i].i = i;
        for(int j = p[i].l ; j <= min(p[i].l+n+5,p[i].r); j++){
            st.insert(j);
        }
    }
    sort(p, p + n, cmp);
    
    vector<int> ans(n);

    for(int i = 0; i < n;){
        auto it = st.lower_bound(p[i].l);
        if(it != st.end() && *it <= p[i].r){
            ans[p[i].i] = *it;
            st.erase(it);
            i++;
        }else{
            for(int j = i-1; j >= 0; j--){
                it = st.upper_bound(max(ans[p[j].i],p[i].l));
                if(it != st.end() && *it <= p[j].r){
                    st.insert(ans[p[j].i]);
                    st.erase(*it);
                    ans[p[j].i] = *it;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)cout<<ans[i]<<' ';cout<<endl;

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

