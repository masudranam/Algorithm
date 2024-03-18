#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 1e7 + 10;


pair<int,int> id[N];

void solve(){
    int n; cin >> n;
   
    ar<long long int,3> ans{1ll*M*M,-1,-1};
    for(int i = 0; i < N; i++){
        id[i].first = id[i].second = 0;
    }
    
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(id[x].first == 0)id[x].first = i;
        else{
            ans = min(ans,{x,id[x].first,i});
            id[x].second = i;
        }
    }

    for(int i = 1; i < N; i++){
        int a = 0;

        for(int j = i; j < N; j += i){
            if(a && id[j].first){
                ans = min(ans,{(a/i)*1ll*j,id[a].first,id[j].first});
                break;
            }
            if(id[j].first)a = j;
        }
    }

    if(ans[1] > ans[2])swap(ans[1],ans[2]);
    cout<<ans[1]<<' '<<ans[2]<<endl;

    
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

