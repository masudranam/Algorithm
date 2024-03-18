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
vector<int> b, B;

for(int i = 0; i < sz(s); i++){
    if(s[i] == 'B'){
        if(!B.empty())B.pop_back();
    }else if(s[i] == 'b'){
        if(!b.empty())b.pop_back();
    }else if(s[i] >= 'a' && s[i] <= 'z')b.push_back(i);
    else B.push_back(i);
}
set<int> st;
for(auto x: b)st.insert(x);
for(auto x: B)st.insert(x);
for(auto x: st)cout<<s[x];
cout<<endl;
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

