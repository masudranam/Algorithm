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
const int N = 5e5 + 10;

void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> mn(n),mx(n);

    for(auto &x: mx) cin >> x;
    for(auto &x: mn) cin >> x;

    if(mx[0] != mn[0]){
        cout<<"NO\n"; return;
    }

    vector<int> ans(n,-M*M),id;
    id.push_back(0);
    ans[0] = mn[0];
    bool f = 0;

    for(int i = 1; i < n; i++){
        if(mx[i-1] > mx[i] || mn[i-1] < mn[i]){
            f = 1;break;
        }
        if(mx[i-1] < mx[i] && mn[i-1] > mn[i]){
            f = 1;break;
        }
        if(mx[i-1] < mx[i]){
            id.push_back(i);
            ans[i] = mx[i];
        }
        if(mn[i-1] > mn[i]){
            id.push_back(i);
            ans[i] = mn[i];
        }
    }
    
    if(f){
        cout<<"NO\n"; return;
    }

    if(id.back() != n-1){
        ans[n-1] = ans[id.back()];
        id.push_back(n-1);
    }

    for(int i = 1; i < sz(id); i++){
        int len = id[i] - id[i-1];
        int x = abs(ans[id[i]]-ans[id[i-1]]);
        x = (x+len-1)/len;
        if(x > d){
            cout<<"NO\n"; return;
        }
        if(ans[id[i-1]] <= ans[id[i]]){
            for(int k = id[i-1]+1; k < id[i]; k++){
                ans[k] = ans[k-1] + x;
                ans[k] = min(ans[k],ans[id[i]]);
            }
        }else{
            for(int k = id[i]-1; k > id[i-1]; k--){
                ans[k] = ans[k+1] + x;
                ans[k] = min(ans[k],ans[id[i-1]]);
            }
        }
    }

    for(int i = 1; i < n; i++){
        if(abs(ans[i]-ans[i-1]) > d){
           cout<<"NO\n";return;
        }
        assert(ans[i] != -M*M);
    }

    cout<<"YES\n";
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
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

