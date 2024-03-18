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
const int N = 3e7 + 10;

void solve(){
    int n , k;
    cin >> n >> k;
    set<int> st;

    for(int i = 10*n; i <= 15*n; i++){
        st.insert(i);
    }

    vector<int> ans{1};

    for(int i = 2; i <= n; i++){
        if((i-1)/2 <= k){
            ans.push_back(i);
            k -= (i-1)/2;
        }else{
            int l = i-2*k;
            ans.push_back(i+l-1);
            k = 0;
            break;
        }
    }


    if(k > 0){
        cout<<-1<<endl;
        return;
    }
    int i = 0;
    while(sz(ans) < n){
        ans.push_back(i*n+N);
        i++;
    }

    print(ans);


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

