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
const int N = 1e5 + 10;

int block = 450;
int nxt[N],last[N],step[N],a[N];
int n, q;

bool same(int x, int y){
    if(max(x,y) == n)return false;
    return x/block == y/block;
}

void upd(int i){
    if(i + a[i] >= n){
        nxt[i] = n;
        last[i] = i;
        step[i] = 1;
    }else if(same(i,i+a[i])){
        nxt[i] = nxt[i+a[i]];
        last[i] = last[i+a[i]];
        step[i] = 1 + step[i+a[i]];
    }else{
        nxt[i] = i + a[i];
        step[i] = 1;
        last[i] = last[i+a[i]];
    }
}

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

void solve(){
   cin >> n >> q;

   for(int i = 0; i < n; i++){
    cin >> a[i];
   }

   for(int i = n-1; i >= 0; i--){
        upd(i);
   }

   while(q--){
    int c,x,y;
    cin >> c >> x;
    
    if(c){
        int ans = 0, pos = x-1;
        for(int i = x-1; i < n; i = nxt[i]){
            ans += step[i];
            pos = last[i];
        }
        cout<<pos+1<<' '<<ans<<endl;
    }else{
        cin >> y;
        x--;
        a[x] = y;
        for(int i = x; i >= 0 && same(i,x); i--){
            upd(i);
        }
    }
   }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

