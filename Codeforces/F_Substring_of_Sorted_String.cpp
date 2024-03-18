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
    int n; cin >> n;
    string s; cin >> s;
    set<int> st[26];
    for(int i = 0; i < n; i++){
        st[s[i]-'a'].insert(i);
    }

    int q; cin >> q;
    while(q--){
        int id; cin >> id;
        int l, r; cin >> l;
        l--;
        if(id == 1){
            char c; cin >> c;
            st[s[l]-'a'].erase(l);
            st[c-'a'].insert(l);
            s[l] = c;
            continue;
        }
        cin >> r, r--;

        int mn = r+1;
        string ans = "Yes";

        for(int i = 25; i >= 0; i--){
            auto it = st[i].upper_bound(r);

            if(it != st[i].begin()){
                it--;
                if(*it >= l && *it > mn){
                    ans = "No";break;
                }
            }
            it = st[i].lower_bound(l);
            if(it != st[i].end()){
                mn = min(mn,*it);
            }
        }
        if(ans == "No"){
            cout<<ans<<endl;
            continue;
        }

        

    }
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

