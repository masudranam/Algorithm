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

bool ok(int x, int l, vector<pair<int,int>>&a){
    int n = sz(a);
    for(int i = 0; i < n; i++){
        if(n-i < x)return false;
        multiset<int> st;
        int cur = 0, ans = M;
        for(int j = i; j < n; j++){
            st.insert(a[j].second);
            cur += a[j].second;
            while(sz(st) > x){
                cur -= *st.rbegin();
                st.erase(--st.end());
            }
            if(sz(st) == x){
                ans = min(ans, cur + (a[j].first - a[i].first));
            }
        }
        if(ans <= l && sz(st) == x)return true;
    }

    return false;
}

void solve(){
    int n; cin >> n;
    int l; cin >> l;

    vector<pair<int,int>> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].second >> a[i].first;
    }
    sort(all(a));

    int l1 = 1, r = n;

    while(r - l1 > 0){
        int m = (l1 + r + 1) / 2;
        if(ok(m,l,a))l1 = m;
        else r = m-1;
    }

    if(ok(l1,l,a))cout << l1 << endl;
    else cout << 0 << endl;
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

