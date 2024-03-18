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

struct node{
    int l, r;
    char s;
};

void solve(){
  string s; cin >> s;
  vector<node> v{{0,0,s[0]}};

  for(int i =1 ; i < sz(s); i++){
    if(v.back().s == s[i])v.back().r++;
    else v.push_back({i,i,s[i]});
  }

  int ans = 0, cnt = 20;

  while(sz(v) > 1){
    v[0].r--;v.back().l++;
    for(int i = 1; i < sz(v)-1; i++){
        v[i].l++,v[i].r--;
    }

    vector<node>tmp;
    for(int i = 0; i < sz(v); i++){
        if(v[i].r - v[i].l >= 0){
            if(tmp.empty())tmp.push_back(v[i]);
            else{
                if(tmp.back().s == v[i].s){
                    tmp.back().r += (v[i].r-v[i].l+1);
                }else{
                    tmp.push_back(v[i]);
                }
            }
        }
    }
    v = tmp;
    ans++;
  }

  for(auto it : v){
    //cout<<it.fs.fs<<' '<<it.fs.sc<<' '<<it.sc<<endl;
  }

  cout << ans << endl;
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

