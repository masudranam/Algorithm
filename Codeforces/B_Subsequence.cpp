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
    string s; 
    getline(cin,s);

    vector<int> id[26];

    for(int i = 0; i < sz(s); i++){
        id[s[i]-'a'].push_back(i);
    }

    int q; cin >> q;
    cin.ignore();

    while(q--){
        string t;
      
        getline(cin,t);
       // cin.ignore();
       // cout << t << endl;
        int cur = 0, f = 0;
   
        for(int i = 0; i < sz(t); i++){
            auto it = lower_bound(all(id[t[i]-'a']),cur);
            if(it == id[t[i]-'a'].end()){
                f = 1;break;
            }else{
                cur = (*it ) + 1;
            }
        }
        if(f)cout <<"NO\n";
        else cout <<"YES\n";
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t; cin.ignore();
   for (int tc = 1; tc <= t; tc++) {
      cout<<"Case "<<tc<<":\n";
      solve();
   }
   return 0;
}

