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

bool ok(string a, string b){
   string s = a, t = b;
   while(sz(s) && s.back() == '0')s.pop_back();
   while(sz(t) && t.back() == '0')t.pop_back();
   if(s == t)return true;
   return false;
}

void solve(){
   // srand(time(0));
   //   int n; cin >> n;
      int n = rand() % 6;
     vector<string> v(n);
      // cout << n << endl;
     bool flag = false;
     for(int i = 0; i < n; i++){
      // cin >> v[i];
         int x = rand() % 10000;
         if(rand() % 2 == 0){
            x *= pow(10, rand() % 5);
         }
         v[i] = to_string(x);
         // cout << v[i] << " ";
      if(v[i].back() == '0') flag = true;
         
     }
   //   cout << endl;
     sort(all(v));
     string s = "";
     int id = -1;
     for(int i = 0; i < n; i++){
      if(v[i].back() == '0'){
         if(sz(s) == 0)s = v[i],id = i;
         else{
            if(ok(s,v[i]))s = v[i],id = i;
         }
      }
     }
      string ans = "";
     if(id == -1){
         for(int i = sz(v)-1; i >= 0; i--){
            ans += v[i];
         }
         // cout<<endl;return;
     }
     else{
         for(int i = sz(v)-1; i>=0 ;i--){
            if(i == id)continue;
            ans += v[i];
      }
      ans += v[id];
     }
     sort(all(v));
     string perfect_ans = "";
     do{
         string p = "";
         for(auto x: v){
            p += x;
         }
         if(p > perfect_ans){
            if(flag && p.back() == '0'){
               perfect_ans = p;
            }
            else if(!flag) perfect_ans = p;
         }
     }while(next_permutation(all(v)));
     if(perfect_ans != ans) {
      cout << n << endl;
      for(auto x: v) cout << x << " ";
      cout << endl;
      cout << "Your ans = " << ans << endl;
      cout << "Correct ans = " << perfect_ans << endl;
      exit(0);
     }
      // cout << perfect_ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; ; tc++) {
      cout<<"Case "<<tc<<": " << endl;
      solve();
   }
   return 0;
}

