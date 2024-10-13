#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int k; cin >> k;
    map<int,int> cnt;
    int tot = 0;

    for(int i = 0; i < 62; i++){
        if(n & (1ll << i)){
            cnt[i]++;
            tot++;
        }
    }
    if(tot > k){
        cout << "No\n";
        return;
    }

    while(tot < k){
        int x = prev(cnt.end())->first;
        cnt[x]--;
        cnt[x - 1] += 2;
        if(cnt[x] == 0)cnt.erase(x);
        tot++;
    }
    int res = prev(cnt.end())->first;

    tot = 0;
    cnt.clear();
    for(int i = 0; i < 62; i++){
        if(n & (1ll << i)){
            cnt[i]++;
            tot++;
        }
    }

    while(tot < k){
        int x = prev(cnt.end())->first;
        if(x <= res){
            x = cnt.begin()->first;
        }
        cnt[x]--;
        cnt[x - 1] += 2;
        tot++;
        if(cnt[x] == 0)cnt.erase(x);
    }

    cout << "Yes\n";
    while(tot--){
        int x = prev(cnt.end())->first;
        cout << x <<' ';
        cnt[x]--;
        if(cnt[x] == 0)cnt.erase(x);
    }


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
