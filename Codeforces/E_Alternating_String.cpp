#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    if(n % 2 == 0){
        int odd = 0, even = 0;
        map<char,int> o, e;
        for(int i = 0; i < n; i++){
            if(i & 1){
                e[s[i]]++;
                even = max(even, e[s[i]]);
            }else{
                o[s[i]]++;
                odd = max(odd, o[s[i]]);
            }
        }
        cout << n - odd - even << '\n';return;
    }

    map<char,int> o, e;
    map<char, int> o1, e1;
    for(char c = 'a'; c <= 'z'; c++){
        o[c] = e[c] = o1[c] = e1[c] = 0;
    }
    
    for(int i = 0; i < n; i++){
        if(i & 1)e[s[i]]++;
        else o[s[i]]++;
    }

  
    int res = 0;
    
    for(int i = 0; i < n; i++){
        if(i & 1)e[s[i]]--;
        else o[s[i]]--;

        int odd = 0, even = 0;
        
        for(auto it : o){
            odd = max(odd, e1[it.first] + it.second);
        }
        for(auto it : e){
            even = max(even, it.second + o1[it.first]);
        }
        //debug(odd);debug(even);
        res = max(res, odd + even);
        if(i & 1)e1[s[i]]++;
        else o1[s[i]]++;
    }
    cout << n - res << '\n';
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
