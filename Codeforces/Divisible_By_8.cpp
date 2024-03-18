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
  
    int cur = 0;
    for(int i = 0; i < sz(s); i++){
        cur = (cur*10 + (s[i]-'0'))%8;
    }
    return cur == 0;
}



void solve(){
    int n;cin >> n;
    string s; cin >> s;
    if(ok(s)){
        cout<<s<<endl;return;
    }
    char c = s.back();
    
    if(n == 1){
        cout<<"8"<<endl;
        return;
    }
    char d = s[1];


    for(char i = '0'; i <= '9'; i++){
        s[n-1] = i;
        if(ok(s)){
            cout<<s<<endl;
            return;
        }
    }
    s[n-1] = c;

    for(char  i = '0'; i <= '9'; i++){
        s[1] = i;
        if(ok(s)){
            cout<<s<<endl;
            return;
        }
    }

    for(char c = '1'; c <= '9'; c++){
        for(char d = '0'; d <= '9'; d++){
               s[1] = c;
               s[n-1] = d;
               if(ok(s)){
                cout<<s<<endl;return;
               }
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

