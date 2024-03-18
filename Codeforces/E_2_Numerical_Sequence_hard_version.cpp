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

int Calc(int x){
    return x*(x+1)/2;
}

int get(int x,bool f){
    int pw = 1, cur = 0, prv = 0;

    for(int len = 1;; len++){
        int cnt;
        if(pw*10 - 1 < x){
            cnt = 10*pw - pw;
            if(f){
                cur += prv*cnt + Calc(cnt)*len;
                prv += cnt*len;
            }else{
                cur += cnt*len;
            }
        }else{
            cnt = x - pw + 1;
            if(f){
                cur += prv * cnt + Calc(cnt)*len;
                prv += cnt*len;
            }else{
                cur += cnt*len;
            }
            break;
        }
        pw *= 10;
    }
    return cur;
}



void solve(){
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        k--;
        int l = 1, r = M;
        while(r-l > 0){
            int m = (l+r)/2;
            if(get(m,1) <= k)l = m + 1;
            else r = m;
        }
        k -= get(r-1,1);
        l = 1;

        while(r - l > 0){
            int m = (l+r)/2;
            if(get(m,0) <= k)l = m + 1;
            else r = m;
        }
        k -= get(r-1,0);
        cout<<to_string(r)[k]<<endl;
    }


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

