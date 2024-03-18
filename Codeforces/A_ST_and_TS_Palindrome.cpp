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

bool ok(string &s){
    int n = sz(s);
    int i = 0, j= n-1;
    while(i < j){
        if(s[i] != s[j])return false;
        i ++, j--;
    }
    return true;
}


void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string r = s;
    reverse(all(r));

    if(k <= n){
        string f = s.substr(0,k);
        string l = s.substr(n-k);
        
        reverse(all(f));
        string one = s + f;
        string two = f + s;
        if(ok(one) && ok(two))cout<<"Yes\n";
        cout<<"No\n";
        return;
    }else{
        if(s == r)cout<<"Yes\n";
        else cout<<"No\n";
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

