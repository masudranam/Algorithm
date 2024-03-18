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
    int n, q;
   cin >> n >> q;
    vector<int> a(n);
    map<int,int>mp;
    set<int> st;

    for(int i = 0;i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    int m = 0;
    while(mp[m])m++;
    st.insert(m);

    while(q--){
        int i, k;
        cin >> i >> k, i--;
        mp[a[i]]--;
        if(mp[a[i]] == 0){
            if(*st.begin() > a[i])st.insert(a[i]);
        }
        a[i] = k;
        mp[a[i]]++;
        if(st.find(k) != st.end())st.erase(k);

        if(sz(st) == 0){
            while(mp[k])k++;
            st.insert(k);
        }
        cout<<*st.begin()<<endl;
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

