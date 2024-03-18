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
    int n;
    cin >> n;

    int a[6][6][50][50] ={0}, b[6][6][50][50];

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int x = 0, y = 0;

        for(auto c: s){
            x += (c-'0');
        }

        a[sz(s)][0][x][0]++;
        
        for(int j = sz(s)-1; j > 0; j--){
            y += (s[j]-'0');
            a[sz(s)][sz(s)-j][x][y]++;
        }

        b[sz(s)][0][x][0]++;
        y = 0;

        for(int j = 0; j+1 < sz(s); j++){
            y += (s[j]-'0');
            b[sz(s)][j+1][x][y]++;
        }

        y = 0;
        ans += 2*a[sz(s)][0][x][0];

        for(int j = 0; j+1< sz(s);j++){
            y += (s[j]-'0');
            
            int baki = sz(s)-2*(j+1);
            int cur_s = x-2*y;

            if(baki > 0 && cur_s > 0){
                ans += a[baki][0][cur_s][0];
            }
        }

        y = 0;

        for(int j = sz(s)-1; j > 0; j--){
            y += (s[j]-'0');
            int baki = sz(s)-2*(sz(j)-j);
            int cur_s = x-2*y;
            if(baki > 0 && cur_s>0){
                ans += a[baki][0][cur_s][0];
            }
        }

        for(int k = 1; k < 5; k++){
            for(int j = k; j <= 9*k;j++){
                int baki = sz(s) + 2*k;
                int cur_s = x + 2*j;
                if(baki < 6 && cur_s < 46){
                    ans += a[baki][k][]
                }
            }
        }


    }
   

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

