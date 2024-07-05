#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> id[1030];

void solve(){
    int n, x;
    cin >> n >> x;

    set<int> s;
    vector<int> c(n),a(n,x);
    
    for(int i = 0; i < n; i++){
        s.insert(i);
        cin >> c[i];
        id[c[i]].push_back(i);
    }

    int res = 0;
    for(int i = 1; i <= 1000; i++){
        if(id[i].empty())continue;
        while(!id[i].empty()){
            int j = id[i].back();
            id[i].pop_back();
            auto it = s.lower_bound(j);
            if(it == s.begin())continue;
            it--;

            int cur = 0;
            vector<int> bad;

            while(true){
                int mn = min(a[*it], c[j] - cur);
                cur += mn;
                bad.push_back(*it);
                if(cur == c[j])break;
                if(it == s.begin())break;
                it--;
            }
            if(cur == c[j]){
                res += 1;
                while(bad.size()){
                    if(cur >= a[bad.back()]){
                        cur -= a[bad.back()];
                        s.erase(bad.back());
                    }else{
                        a[bad.back()] -= cur;
                        cur = 0;
                    }
                    bad.pop_back();
                }
            }
        }
    }
    for(int i = 0; i <= 1000; i++)id[i].clear();
    cout << res << '\n';
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
