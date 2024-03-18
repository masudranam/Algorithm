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
    vector<int> a(3);
    for(auto &x: a)cin >> x;

    int s = a[0] + a[1] + a[2];

    if(s % 3 == 0){
        if(a[0] == a[1] && a[0] == a[2]){
            cout<<"YES\n";return;
        }
    }
sort(all(a));

    if(s % 4 == 0){
        if(a[2] % 2== 0 && a[2]/2 == a[0] && a[0] == a[1]){
            cout<<"YES\n";return;
        }
    }

    if(s % 5 == 0){
        if(a[2] % 2 == 0 && s/5 == a[2]/2 && a[1]%2 == 0 && a[1]/2 == s/5 && a[0] == s/5){
            cout<<"YES\n";return;
        }

        if(a[2] % 3 == 0 && s/5 == a[2]/3 && a[0] == s/5 && a[1] == s/5){
            cout<<"YES\n";return;
        }
    }
    if(s%6 == 0){
        if(a[0] % 2 == 0 && a[0]/2 == s/6 && a[1]%2 == 0 && a[1]/2 == s/6 && a[2]%2 == 0 && a[2]/2 == s/6){
            cout<<"YES\n";return;
        }
        if(a[1]%2 == 0 && a[1]/2 == s/6 && a[2]%3 == 0 && a[2]/3 == s/6 && a[0] == s/6){
            cout<<"YES\n";return;
        }   
        if(a[2]%4 == 0 && a[2]/4 == s/6 && a[0] == s/6 && a[1] == s/6){
            cout<<"YES\n";return;
        }
    }
    cout<<"NO\n";
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

