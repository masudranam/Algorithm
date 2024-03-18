#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 998244353;
const int N = 2e5 + 10;

int f[N];
void solve(){
    
    string s; cin >> s;
    int n = sz(s);
    vector<int>b;
    assert(sz(s) < N);

    int cnt = 0;
    char c = '0';

    for(int i = 0; i < n; i++){
        if(c == s[i])cnt++;
        else{
            if(cnt>1)b.push_back(cnt);
            cnt = 1;
            c = s[i];
        }
    }

    if(cnt>1)b.push_back(cnt);
   

    int fst = 0, sc = 1;

    for(auto x: b){
        fst += (x-1);
        sc = (sc*x)%M;
    }

    cout<<fst<<' '<<sc*f[fst]%M<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   f[0] = 1;
   for(int i = 1; i < N; i++){
    f[i] = (f[i-1]*i)%M;
   }

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}