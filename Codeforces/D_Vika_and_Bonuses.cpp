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
int S, K;

int get(int k){
    if(S % 10 == 0) return S*K;
    if(S % 5 == 0)return max((S+5)*(K-1), S*k);
    int k1 = k;
    int s = S;

    while(s % 10 != 2){
        if(k == 0)return s*(K-k1);
        s += s%10;
        k--;
    }

    if(k == 0) return s*(K-k1);
    vector<int> f{2,6,14,20};
    int x = ((k-1) / 4) * 20;

    return (s + x + f[(k-1)%4])*(K - k1);
}

void solve(){
    cin >> S >> K;
    
    int l = 0, r = K;
    while(r - l > 5){
        int m = (l+r)/2;
        if(get(m) >= get(l) && get(m+1) >= get(m))l = m;
        else r = m;
    }

    int ans = S*K;
    for(int i = max(0ll,l-100); i <= min(K,l+100); i++){
        ans = max(ans,get(i));
    }

    cout << ans << endl;
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

