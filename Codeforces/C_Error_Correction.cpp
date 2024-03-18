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

    vector<int> ans;

    for(int i = 1; i <= n; i++){
        string t; cin >> t;
        if(abs(sz(s) - sz(t)) > 1)continue;

        if(sz(s) == sz(t)){
            int s_i = 0, t_i = 0,cnt = 0;
            while(t_i < sz(t)){
                if(s[s_i] != t[t_i])cnt++;
                s_i++,t_i++;
            }
            if(cnt > 1){
                continue;
            }
        }else if(sz(s) > sz(t)){
            int si = 0, ti = 0, cnt = 0;
            while(si < sz(s)){
                if(s[si] != t[ti])si++,cnt++;
                else si++,ti++;
            }
            if(cnt>1)continue;
        }else{
            int si = 0, ti = 0, cnt = 0;
            while(ti < sz(t)){
                if(s[si] != t[ti])cnt++,ti++;
                else si++,ti++;
            }
            if(cnt > 1)continue;
        }
            ans.push_back(i);
    }
    cout<<sz(ans)<<endl;
    print(ans);
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

