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
    int n, m, k;
    cin >> n >> m >> k;

    map<pair<int,int>,int>cnt;
    vector<int> one(m),l[n+1],r[n+1];
    set<int> st;
    set<pair<int,int>>p;


    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        l[x].push_back(i);
        r[y].push_back(i);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(auto x: l[i])st.insert(x);

        if(sz(st) == 2){
            cnt[{*st.begin(),*st.rbegin()}]++;
            p.insert({*st.begin(),*st.rbegin()});
        }else if(sz(st) == 1){
            one[*st.begin()]++;
        }else if(sz(st) == 0){
            ans++;
        }
        
        for(auto x: r[i])st.erase(x);
    }
    
    int res = 0;
    for(auto i: p){
        res = max(res,cnt[i] + one[i.first]+one[i.second]);
    }
    sort(all(one));
   
    res = max(res,one[m-1]+one[m-2]);
    cout<<res+ans<<endl;    
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

