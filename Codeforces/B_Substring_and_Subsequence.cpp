#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

string a, b;

int get(int x){
    int j = x;
    for(int i = 0; i < a.size() && j < b.size();i++){
        if(a[i] == b[j])j++;
    }
    return x + b.size() - j;
}

void solve(){
    cin >> a >> b;

    int ans = a.size() + b.size();

    for(int i = 0; i < b.size(); i++){
      //  cout << get(i) << '\n';
        ans = min(ans, a.size() + get(i));
    }
    cout << ans << '\n';

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

