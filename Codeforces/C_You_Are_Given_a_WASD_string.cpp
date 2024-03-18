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

bool get(string s,char a, char b,int par){
    int n = sz(s);
    vector<int> ps(n+1);
    int mx = 0, mn = 0,mxp = -1, mnp = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == a)ps[i+1] = 1*par;
        else if(s[i] == b)ps[i+1] = -1*par;
        ps[i+1] += ps[i];
        mx = max(ps[i+1],mx);
        mn = min(ps[i+1],mn);
    } 

    for(int i = 0; i <= n; i++){
        if(ps[i] == mx)mxp = i;
        if(ps[i] == mn && mnp == -1)mnp = i;
    }
   // debug(mnp);debug(mxp);
   // print(ps);
    return (mnp > mxp && (mx-mn>1));
}

void solve(){
    string s; cin >> s;
    int mxx = 0, mnx = 0, x = 0;
    int mxy = 0, mny = 0, y = 0;

    for(int i = 0; i < sz(s); i++){
        if(s[i] == 'W')y++;
        else if(s[i] == 'S')y--;
        else if(s[i] == 'A')x--;
        else x++;
        mxx = max(mxx,x), mnx = min(mnx,x);
        mxy = max(mxy,y), mny = min(mny,y);
    }

    x = get(s,'D','A',1)|get(s,'D','A',-1);
    y = get(s,'W','S',1)|get(s,'W','S',-1);
    int ans = (mxx-mnx+1-x)*(mxy-mny+1);
    ans = min(ans,(mxx-mnx+1)*(mxy-mny+1-y));

    cout<<ans<<endl;
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



