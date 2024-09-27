#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

string get(int x, int len){
    string cur;
    for(int i = 0; i < len; i++){
        if(x & (1 << i))cur += '1';
        else cur += '0';
    }
    return cur;
}

void Put(string s, int k){
    for(int i = 1; i <= k - (int)s.size(); i++){
        cout << '0';
    }
    cout << s << '\n';
}

void solve(){
    int n, k;
    cin >> n >> k;
    string s; cin >> s;

    int len = min(k, 20ll);

    vector<string> a;
    for(int i = 0; i <= (1 << len); i++){
        a.push_back(get(i, len));
    }
    sort(a.begin(), a.end());

    unordered_map<string,int> mp;
    for(int i = len; i <= n; i++){
        mp[s.substr(i - len, len)] = 1;
    }
    for(auto it : mp)cout << it.first <<'\n';
  
    for(int i = 0; i < (int)a.size(); i++){
        if(mp.count(a[i]) == 0){
            Put(a[i], k);return;
        }
    }
    cout << - 1 << '\n';
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
