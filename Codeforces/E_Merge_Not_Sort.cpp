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
    int n; cin >>n;
    vector<int> a(2*n);
    for(auto &x: a) cin >> x;

    vector<int> c;
    int cnt = 1,mx = a[0];
    for(int i = 1; i < 2*n; i++){
        if(a[i] > mx){
            c.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
        mx = max(mx,a[i]);

        if(cnt > n){
            cout<<-1<<endl;
            return;
        }
    }
    c.push_back(cnt);


    vector<int> dp(n+1,0);
    dp[0] = 1;

    for(int i = 0; i < sz(c); i++){
        for(int j = n; j >= c[i]; j--){
            if(dp[j])continue;
            if(dp[j-c[i]]){
                dp[j] = c[i];
            }
        }
        if(dp[n])break;
    }
    //debug(dp[3]);
    if(dp[n] == 0){
        cout<<-1<<endl;return;
    }
    vector<int> seg;
    int j = n;
    while(j > 0){
        seg.push_back(dp[j]);
        j -= dp[j];
    }
   // print(c);
   // print(seg);
    //print(dp);
    vector<int> f,s;

    for(int i = 0,j = 0; i < sz(c); i++){
        if(sz(seg) && seg.back() == c[i]){
            int x = seg.back();
            seg.pop_back();
            while(x-->0){
                f.push_back(a[j++]);
            }
        }else{
            int x = c[i];
            while(x-->0){
                s.push_back(a[j++]);
            }
        }
    }
   // assert(sz(f) == sz(s));
    print(f);
    print(s);

    


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

