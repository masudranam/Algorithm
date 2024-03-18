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
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    s = "!" + s;
    vector<int> l(k),r(k);
    for(int i = 0; i < k; i++){
        cin >> l[i];
    }
    for(int i = 0; i < k; i++){
        cin >> r[i];
    }

    vector<int> nxt(n+5),cnt(n+5);

    for(int i = 0; i < k; i++){
        for(int j = l[i]; j <= r[i]; j++){
            nxt[j] = l[i] + r[i];
        }
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int a = min(x,nxt[x]-x);
        int b = max(x,nxt[x]-x);
        //cout<<a <<' '<<b<<endl;
        cnt[a]++;
        cnt[b+1]--;
    }
    for(int i = 1;i <= n; i++){
        cnt[i] += cnt[i-1];
    }
    //print(cnt);
    for(int i = 0; i < k; i++){
        for(int j = l[i]; j < (l[i]+r[i]+1)/2; j++){
            if(cnt[j]&1)swap(s[j],s[l[i]+r[i]-j]);
        }
    }
    cout<<s.substr(1)<<endl;

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

