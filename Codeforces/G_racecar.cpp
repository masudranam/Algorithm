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
    int i = 0, j = n-1;
    while(i < j){
        if(s[i] != s[j])return false;
        i++,j--;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    vector<string> v;

    for(int i = 0; i< n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)continue;
            string t = v[i]+v[j];
            if(ok(t)){
                cout<<"Yes\n";return;
            }
        }
    }
    cout<<"No\n";


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

