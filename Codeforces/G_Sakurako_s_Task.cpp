#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

bool ok(int m, int k, int g, vector<int> a){
    if(a.size() + m <= k) return false;
    int cnt = 0;

    vector<int> baki;
    set<int> st;

    for(int i = 0; i < a.size(); i++){
        if(st.find(a[i]) != st.end() || a[i] >= k){
            baki.push_back(a[i]);
        }else{
            cnt++;
            st.insert(a[i]);
        }
    }


    for(int i = 0, j = 0; i < k && j < (int)baki.size();){
        if(st.find(i) != st.end()){
            i += g;continue;
        }
        j++, i += g, cnt++;
    }
    return (cnt + m - 1 >= k);
}

void solve(){
    int n; cin >> n;
    int m; cin >> m;

    vector<int> a(n);
    

    int g = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        
        g = __gcd(g, a[i]);
    }

    if(n == 1){
        if(m > a[0])cout << m << '\n';
        else cout << m - 1 << '\n';
        return;
    }


    sort(a.begin(), a.end());

    int l = 0, r = N * M;
    while(r - l > 0){
        int mid = (l + r + 1) / 2;
        if(ok(m,mid,g,a))l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
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
