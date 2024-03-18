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
    int k; cin >> k;
    string s; cin >> s;
    int b = count(all(s),'B');
    if(b == k){
        cout<<0<<endl;
        return;
    }

     b = 0;
    cout<<1<<endl;

    for(int i = n-1; i >= 0; i--){
        if(b + i+1 == k){
            cout<<i+1<<" B\n";
            return;
        }
        if(b == k){
            cout<<i+1<<" A\n";
            return;
        }
        if(s[i] == 'B')b++;
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

