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

int get(int bit, vector<int> a){
    if(bit == -1)return 0;
    vector<int> o,z;
   // cout<<bit<<"->";print(a);
    for(int i = 0;i < sz(a); i++){
        if(a[i]>>bit&1)o.push_back(a[i]);
        else z.push_back(a[i]);
    }
    
    if(sz(o) == 0) return get(bit-1,z);
    if(sz(z) == 0) return get(bit-1,o);
    
    return min(get(bit-1,o),get(bit-1,z))+(1<<bit);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout<<get(30,a)<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

