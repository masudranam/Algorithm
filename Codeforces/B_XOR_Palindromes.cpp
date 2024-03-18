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
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < n/2; i++){
        cnt += (s[i] != s[n-i-1]);
    }

    int extra = n - 2*cnt;

    for(int i = 0; i <= n; i++){
        if(i < cnt){
            cout<<0;
            continue;
        }
        int baki = i - cnt;
        if(baki > extra){
            cout<<0;
            continue;
        }
        if(baki % 2){
            if(n&1)cout<<1;
            else cout<<0;
        }else{
            cout<<1;
        }
    }
    cout<<endl;

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

