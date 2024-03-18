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

bool ok(string &s, string &t, char c){
    int cnts = count(all(s),c);
    int cntt = count(all(t),c);
    int n = sz(s) / 2;
    if(cnts >= n && cntt >= n)return true;
    return false;
}

string get(string &s, string &t, char c){
    string ans = "";
    int n = sz(s), i = 0, j = 0;

    while(i < n || j < n){
        while(i < n && s[i] != c){
            ans += s[i]; i++;
        }
        while(j < n && t[j] != c){
            ans += t[j]; j++;
        }
        if(i < n)ans += s[i];
        else if(j < n)ans += t[j];
        i++,j++;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    string s[3];
    cin >> s[0] >> s[1] >> s[2];

    for(auto c : {'0', '1'}){
        for(int i = 0; i < 3; i++){
            for(int j = i+1; j < 3; j++){
                if(ok(s[i],s[j],c)){
                    cout << get(s[i],s[j],c)<<endl;
                    return;
                }
            }
        }
    }
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

