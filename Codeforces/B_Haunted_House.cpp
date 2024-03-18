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
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> ans;
    int cur = 0;
    for(int i = n-1, j = n-1;i >= 0; i--){
        if(s[i] == '1'){
            j = min(j,i);
            while(j >= 0 && s[j] == '1')j--;
            if(j == -1)break;
            s[j] = '1';
            cur += (i-j);
        }
        ans.push_back(cur);
    }

    while(sz(ans) < n)ans.push_back(-1);
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

