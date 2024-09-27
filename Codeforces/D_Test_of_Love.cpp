#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    string s; cin >> s;

    for(int i = 0; i < n; i++){
        if(s[i] != 'C')continue;
        for(int j = i-1; j >= 0 && s[j] == 'W'; j--){
            s[j] = 'C';
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'C')cnt++;
        else{
            cnt = 0;
        }
        if(cnt >= m){
            cout << "NO\n";return;
        }
    }
    cnt = 0;
    int tot = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != 'W')continue;
         for(int j = i - 1; j >= 0 && s[j] == 'C'; j--){
            s[j] = 'W';
         }
    }

    //cout << s << '\n';
    for(int i = 0; i < n; i++){
        if(s[i] == 'W')cnt++;
        else{
            tot += max(0ll, cnt - m + 1);
            cnt = 0;
        }
    }
    tot += max(0ll, cnt - m + 1);
    if(tot > k)cout << "NO\n";
    else cout << "YES\n";
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