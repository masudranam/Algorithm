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


/*
>><>><
7 6 4 5 3 1 2
7 6 4 5 3 1 2
*/
void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    string s[n];
    int ans = M;

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    for(int i = 0; i < n; i++){
        int l = 0, r = 0, cnt = 0;
        while(r < m){
            if(s[i][r] == 'x'){
                l = r+1;
                cnt = 0;
            }else{
                cnt += s[i][r] == '.';
                while(r-l+1 > k){
                    cnt -= s[i][l] == '.';
                    l++;
                }
                if(r-l+1 == k){
                    //cout << cnt <<' '<<i<<' '<<r<<endl;
                    ans = min(ans,cnt);

                }
            }
            r++;
        }
    }

    for(int i = 0; i < m; i++){
         int l = 0, r = 0, cnt = 0;
        while(r < n){
            if(s[r][i] == 'x'){
                l = r+1;
                cnt = 0;
            }else{
                cnt += s[r][i] == '.';
                while(r-l+1 > k){
                    cnt -= s[l][i] == '.';
                    l++;
                }
                if(r-l+1 == k){
                    //cout << cnt <<' '<<i<<' '<<r<<endl;
                    ans = min(ans,cnt);

                }
            }
            r++;
        }
    }
    if(ans == M)ans = -1;
    
    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

