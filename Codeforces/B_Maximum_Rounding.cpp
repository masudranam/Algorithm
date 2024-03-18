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

if(s[0] >='5'){
    cout << 1;
    for(int i = 0; i <n; i++){
        cout <<0;
    }
    cout << endl;
    return;
}

int id = -1;
for(int i = 0; i < n; i++){
    if(s[i] >='5'){
        id = i-1;break;
    }
}
if(id != -1){
while(id >=0 && s[id] == '4')id--;
if(id < 0){
    cout <<1;
    for(int i = 0; i < n; i++)cout <<0;
    cout << endl;
    return;
}
s[id]++;
for(int i = id+1; i<n; i++)s[i] = '0';
}

cout << s << endl;

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

