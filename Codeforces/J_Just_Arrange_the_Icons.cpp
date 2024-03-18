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
const int N = 2e6 + 10;

void solve(){
   int a, b, c,d;
   cin >> a >> b >> c >> d;
   vector<string>s(50);

   for(int i = 0; i < 50; i++){
      if(i >= 36){
         s[i] = string(50,'B');
      }else if(i >= 26){
         s[i] = string(50,'C');
      }else if(i >= 13){
         s[i] = string(50,'D');
      }else{
         s[i] = string(50,'A');
      }
   }

   a--, b--, c--, d--;

   for(int i = 1; i+1 < 50; i+=2){
      for(int j = 1; j+1 < 50; j++){
        
            if(s[i-1][j] == s[i+1][j] && s[i][j-1] == s[i][j+1] && s[i-1][j] == s[i][j-1]){
               if(a && s[i][j] != 'A'){
                  s[i][j] = 'A';a--;
               }else if(b && s[i][j] != 'B'){
               s[i][j] = 'B';b--;
               }else if(c && s[i][j] != 'C'){
                  s[i][j] = 'C';c--;
               }else if(d && s[i][j] != 'D'){
                  s[i][j] = 'D';d--;
               }
            }  
      }
   }

   cout << 40 <<' ' << 50 <<endl;
   for(int i = 0; i < 50; i++){
      cout << s[i] << endl;
   }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

