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
    int n, m;
    cin >> n >> m;

    string s; cin >> s;
    int S = 0;
    for(int i = 0; i < n; i++){
        S |= (s[i] - '0') << i;
    }

    vector<int> day(m) , x(m), y(m);

    for(int i = 0; i < m; i++){
        cin >> day[i];
        cin >> s;
        for(int j = 0; j < n; j++){
            x[i] |= (s[j] - '0') << j;
        }
        cin >> s;
        for(int j = 0; j < n; j++){
            y[i] |= (s[j] - '0') << j;
        }
    }


    vector<int> d(1<<n+1,M);
    d[S] = 0;

    set<pair<int,int>>q;
    q.insert({0,S});
   
    while(sz(q)){
        pair<int,int> p = *q.begin();
        q.erase(q.begin());

        for(int i = 0; i < m; i++){
            int v = (p.second & ~x[i])|y[i];
            if(d[v] > p.first + day[i]){
                d[v] = p.first + day[i];
                q.insert({d[v],v});
            }
        }
    }

    if(d[0] >= M)cout<<-1<<endl;
    else cout<<d[0]<<endl;


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

