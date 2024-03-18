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
const int N = 1e7 + 10;

int lpf[N];
vector<int>pfs;
void sieve() {
    for(int i=2; i<N; i++) {
        if(!lpf[i]) {
            pfs.push_back(i);
            lpf[i]=i;
        }
        for(int j=0; j<pfs.size() && pfs[j]<=lpf[i]&& i*pfs[j]<N; j++) {
            lpf[i*pfs[j]]=pfs[j];
        }
    }
}

vector<int> get(int x){
    vector<int> v;
    while(x > 1){
        int y = lpf[x];
        v.push_back(y);
        while(x % y == 0) x /= y;
    }
    return v;
}


void solve(){
    int n; cin >> n;
    vector<int> a(n),b(n);

    for(auto &x : a) cin >> x;
    bool ok = 0;
    set<int> st;
    for(int i = 2; i < N/10; i++)st.insert(i);
    vector<int> vis(N);
    for(auto x : pfs)st.insert(x);

    for(int i = 0; i < n; i++){
        auto it = st.begin();
        vector<int> p;
        vector<int> v;
        bool f = 1;
        if(ok){
            while(true){
                p = get(*it);
                f = 1;
                for(auto x : p){
                    if(vis[x]){
                        f = 0;break;
                    }
                }
                v.push_back(*it);

                if(f){
                b[i] = *it;
                for(auto x: p)vis[x] = 1;
                for(auto x: v)st.erase(x);
                break;
            }
            it++;
            assert(it != st.end());
      }
      continue;
    }
        it = st.lower_bound(a[i]);
        

        while(true){
            p = get(*it);
            f = 1;
            for(auto x : p){
                if(vis[x]){
                    f = 0;break;
                }
            }

            if(f == 1){
                b[i] = *it;
                for(auto x : p)vis[x] = 1;
                if(*it > a[i])ok = 1;
                v.push_back(*it);
                for(auto x: v)st.erase(x);
                break;
            }
            v.push_back(*it);
            it++;
        }
    }

    print(b);
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
sieve();
   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

