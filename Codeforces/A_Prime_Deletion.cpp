#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> get(string &s){
    vector<int> v;
    for(int i = 0; i < 9; i++){
        for(int j = i+1; j < 9; j++){
            string t;
            t += s[i];
            t += s[j];
            v.push_back(stoi(t));
        }
    }
    return v;
}
bool ok(int x){
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0)return false;
    }
    return true;
}

void solve(){
    string s; cin >> s;
    vector<int> v = get(s);
    for(auto x: v){
        if(ok(x)){
            cout<<x<<endl;return;
        }
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

