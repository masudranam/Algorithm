#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1.6e9 + 7;
const int N = 2e3 + 10;

int get(int x, int y){
    if((M*M)/x < y) return M*M;
    return x*y;
}

void solve(){
    int n, q;
    cin >> n >> q;
    map<int,int> id;
    vector<int> a;
    vector<pair<int,int>>b;
    b.push_back({0,0});

    for(int i = 0; i <n; i++){
        int x, t; 
        cin >> t >> x;
        if(b.back().first == M*M)continue;

        if(t == 1){
            a.push_back(x);
            b.push_back({b.back().first+1,b.back().first+1});
            id[b.back().first] = sz(a)-1;
        }else{
            int cur = get(b.back().first,x+1);
            b.push_back({cur,b.back().second});
            id[b.back().first] = sz(a)-1;
        }
    }
    vector<int> ans(q);
   

    for(int i = 0; i < q; i++){
        int k ;cin >> k;
        int cnt = 10;
        while(k > 0){
            pair<int,int> p{k,0};
            auto it = lower_bound(all(b),p);
            p = *it;

            if(p.first == k){
                ans[i] = a[id[p.first]];
                break;
            }
            pair<int,int> p1 = (*--it);
            if(k % p1.second == 0){
                ans[i] = a[id[p.first]];
                break;
            }
           p = p1;

            int x = ((k - 1)/p.second)*p.second;
            k -= x;
        }
      
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] <<' ';
    }
    cout << endl;
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

