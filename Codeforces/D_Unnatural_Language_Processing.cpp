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

    string t; 
    for(int i = 0; i < n; i++){
        if(s[i] == 'a' || s[i] == 'e')t += 'V';
        else t += 'C';
    }

    string ans;

    for(int i = 0; i < n; i++){
        if(i == 0){
            ans += s[i];continue;
        }
        if(t[i] == 'V' && t[i-1] == 'C'){
            ans.pop_back();
             ans += '.';
            ans += s[i-1];
            ans += s[i];
        }else{
            ans += s[i];
        }
    }
    if(ans[0] == '.')ans.erase(ans.begin());
    
    cout << ans << endl;

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

