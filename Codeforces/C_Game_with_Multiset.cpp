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
    vector<int> cnt(35),tmp(35);

    for(int i = 0; i < n; i++){
        int t; cin >> t;
        int w; cin >> w;
        if(t == 1){
            cnt[w]++;
        }else{
            tmp = cnt;
            bool f = 1;
            for(int j = 0; j < 31; j++){
                if(w&(1<<j)){
                    if(tmp[j] == 0){
                        cout<<"NO\n";
                        f = 0;
                        break;
                    }
                    tmp[j]--;
                }
                tmp[j+1] += tmp[j]/2;
            }
            if(f == 1){
                cout<<"YES\n";
            }
        }

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

