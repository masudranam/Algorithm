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
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    stack<int> stk;

    for(int i = 0; i < n; i++){
        if(stk.empty()){
            stk.push(a[i]);
            continue;
        }

        if(stk.top() == a[i]){
            int x = a[i];
            while(!stk.empty()){
                if(stk.top() == x){
                    stk.pop();
                    x++;
                }else break;
            }
            stk.push(x);
        }else stk.push(a[i]);
    }
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(all(ans));
    cout << sz(ans) << endl;
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

