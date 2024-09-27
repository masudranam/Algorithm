#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
//#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e6 + 10;

int mp[N];
unordered_map<int,int> mpi[5002];

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
   
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
            mp[a[i]^a[j]] = 0;
            }
        }
    }
  
    
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            res += 8 * mp[a[i]^a[j]];
            mp[a[i] ^ a[j]]++;
        }
    }
    
    cout << res << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}