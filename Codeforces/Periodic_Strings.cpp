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

int get(string &s){
    int n = sz(s);
    for(int i = 1; i <= n; i++){
        int k = 0, f = 1;
        for(int j = i; j < n && f; j++){
            if(j % i == 0)k++;
            int cur = (j-k)%i;
            if(cur < 0)cur += i;
            f &= (s[cur] == s[j]);
        }
        if(f)return i;
    }
    return n;
}

void solve(){
    string s;

    while(cin >> s){
        cout<<get(s)<<endl;
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

