#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, k;
    cin >> n >> k;  
    int a[n],b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<pair<int,int>>s;
    int ans = 0,as = 0, bs = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]){
            s.push_back({b[i],a[i]});
            as += a[i];
            bs += b[i];
        }
    }
    if(k == 0){
        cout << bs - as << endl;
        return;
    }

    n = s.size();
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    ans = 0;

    priority_queue<pair<int,int>>q;

    int tota = 0, totb = 0;
    
    for(int i = 0; i < n; i++){
        q.push({s[i].second,s[i].first});
      //  cout << s[i][0] <<' '<<s[i][1] <<' '<<s[i][2]<<endl;
        as -= s[i].second, bs -= s[i].first;
        totb += s[i].first;
        tota += s[i].second;

        while(q.size() > k){
            pair<int,int> p = q.top();
            q.pop();
            //cout << p.first <<' '<<p.second <<' '<<bs <<' '<<(as+tota)<<endl;
            totb -= p.second;
            tota -= p.first;
            ans = max(ans, bs - (as + tota));
        }
        if(q.size() == k){
            ans = max(ans, bs - (as + tota));
        }
    }
    cout << ans << endl;

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

