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
const int N = 2e6 + 10;

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

int get(map<int,int> &mp){
    int ans = 1;
    for(auto it : mp){
        ans = (ans * (it.second + 1));
    }
    return ans;
}

void add(map<int, int> &mp, int x){
    while(x > 1){
        int y = lpf[x];
        while(x % y == 0) x /= y, mp[y]++;
    }
}

bool ok(map<int, int > &mp, int d){
    // for(int i = 0; pfs[i]*pfs[i] <= d; i++){
    //     if(d % pfs[i])continue;
    //     int cnt = 0;
    //     while(d % pfs[i] == 0)cnt++, d/=pfs[i];
    //     if(mp[pfs[i]] < cnt)return false;
    // }
    // if(d > 1 && mp.find(d) == mp.end())return false;
    // return true;

    for(auto it : mp){
        for(int i = 0; i < it.second; i++){
            if(d % it.first == 0) d /= it.first;
            else break;
        }
        if(d == 1)break;
    }
    return d == 1;
}

void solve(){
    int n, q;
    cin >> n >> q;

    map<int,int> mp;
    add(mp,n);

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int a; cin >> a;
            add(mp,a);
            int d = get(mp);
            if(ok(mp,d))cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            mp.clear();
            add(mp,n);
        }
    }
    cout<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
    sieve();
   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

