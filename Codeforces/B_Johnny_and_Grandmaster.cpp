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


int pw(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = (res*a)%M;
        a = (a*a) % M;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, p;
    cin >> n >> p;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(p == 1){
       cout << (n&1) << endl;
        return;
    }

    sort(all(a));

 
    vector<pair<int,int>> stk;

    for(int i = n-1; i >= 0; i--){
        if(stk.empty()){
            stk.push_back({a[i],1});
            continue;
        }
        if(stk.back().first == a[i])stk.back().second++;
        else{
            for(int k = stk.back().first-1; k > a[i]; k--){
                stk.push_back({k,0});
            }
            stk.push_back({a[i],1});
        }
    }



    reverse(all(stk));
    while(sz(stk) && stk.back().second % 2 == 0){
        stk.pop_back();
    }


for(int i = 0; i < sz(stk); i++){
    //cout << stk[i].first <<' '<<stk[i].second << endl;
}
    int j = sz(stk)-1;

    for(int i = sz(stk)-2; i >= 0; i--){
        for(int k = i ; k + 1< j && (stk[k].second/p); k++){
            stk[k+1].second += stk[k].second/p;
            stk[k].second %= p;
        }
        if(j >= 0){
            stk[j].second %= 2;
        }
        if(j > 0 && stk[j].second <= (stk[j-1].second/p)){
            stk[j-1].second -= stk[j].second*p;
            j--;
        }
       
    }

    int ans = 0;
    while(j >= 0 && stk[j].second%2 == 0)j--;

    if(j >= 0)ans = stk[j].second*pw(p,stk[j].first)%M;

    for(int k = j-1; k >= 0; k--){
        if(stk[k].second == 0)continue;
        int x = pw(p,stk[k].first);
        x = (x*stk[k].second)%M;
        ans = (ans - x)%M;
        ans = (ans + M)%M;
    }

    cout << (ans + M) % M << endl;

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

