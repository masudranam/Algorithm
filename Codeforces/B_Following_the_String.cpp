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
    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    string s = string(n,'0');

    for(char c = 'a'; c <= 'z'; c++){
        int cur = n+1;
        for(int i =n -1; i >= 0; i--){
            if(s[i] != '0' || cur == -1)continue;
            if(cur == a[i])s[i] = c,cur--;
            else if(cur == n+1){
                cur = a[i] - 1;
                s[i] = c;
            }
        }
    }
    char c = 'z';
    for(int i = 0; i < n; i++){
        if(s[i] == '0')s[i] = c--;
    }
    cout << s <<endl;
    
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

