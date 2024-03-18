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
    int n, q;
    cin >> n >> q;
    string s; cin >> s;
    set<int> open, close;

    for(int i = 0; i < n; i++){
        if(s[i] == '(' && i+1 < n && s[i+1] == '('){
            open.insert(i);
        }
        if(i && s[i] == ')' && s[i-1] == ')')close.insert(i);
    }

    while(q--){
        int x; cin >> x, x--;

        if(s[x] == '('){
            if(x+1 < n){
                if(s[x+1] == '(')
                open.erase(x);
                else close.insert(x+1);
            }
            if(x){
                if(s[x-1] == '(')
                open.erase(x-1);
                else close.insert(x);
            }
            s[x] = ')';
        }else{
            if(x){
                if(s[x-1] == ')'){
                    close.erase(x);
                }else{
                    open.insert(x-1);
                }
            }
            if(x+1 < n){
                if(s[x+1] == ')')close.erase(x+1);
                else open.insert(x);
            }
            s[x] = '(';
        }
        bool f = false;
        f |= (sz(open) == 0 && sz(close));
        f |= (sz(close) == 0 && sz(open));
        f |= (s[0] == ')');
        f |= (s.back() == '(');
        f |= (n&1);
        if(sz(open) && sz(close)){
            if(*open.begin() > *close.begin()) f = 1;
            if(*open.rbegin() > *close.rbegin()) f = 1;
        }
        if(f)cout <<"NO\n";
        else cout <<"YES\n";
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

