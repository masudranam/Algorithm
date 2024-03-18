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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>>a(k);
    vector<int> ans;

    int cnt = n/k, cur = 1,extra = n % k;

    for(int i = 0; i < k; i++){
        for(int j = 1; j <= (cnt + (extra > 0)); j++){
            a[i].push_back(cur++);
        }
        extra--;
    }

 
    
    for(int i = 1; i < k; i+=2){
        reverse(all(a[i]));
    }

   

    for(int i = 0; i < (n/k)+1; i++){
        for(int j = 0; j < k; j++){
            if(sz(a[j]) > i){
                ans.push_back(a[j][i]);
            }
        }
    }

print(ans);
    
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

