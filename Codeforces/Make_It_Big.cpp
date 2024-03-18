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
    string s; cin >> s;
    int n = sz(s);
    int ans =0;
    auto get = [&](string s){
        int cur = 0;
        for(auto c: s){
            cur = (cur*10 + (c-'0'));
        }
        return cur;
    };

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            string t = s;
            swap(t[i],t[j]);
            for(int k = 0; k < n; k++){
                for(int l = k+1; l < n; l++){
                    string x = t;
                    swap(x[k],x[l]);
                    int y = stoi(x);
                    ans = max(ans,y);
                }
            }
        }
    } 
    cout<<ans<<endl;
   
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

