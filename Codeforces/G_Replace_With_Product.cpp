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
    
    int cur = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> idx;

    for(int i = 0; i < n; i++){
        cur *= a[i];
        if(a[i] > 1)idx.push_back(i);
        if(cur >= 3*n)break;
    }
   
    if(cur >= 3*n || sz(idx) >= 25){
        int l = 0, r = n-1;
        while(a[l] == 1)l++;
        while(a[r] == 1)r--;
        cout<<l+1<<' '<<r+1<<endl;
        return;
    }

    vector<int> ps(n+2);
    for(int i = 0; i < n; i++){
        ps[i+1] = ps[i]+a[i];
    }

    int ans = 0;
    int l = 0, r = 0;
    for(int i = 0; i < sz(idx); i++){
        int cur = 1;
        for(int j = i; j < sz(idx); j++){
            cur *= a[idx[j]];
            int val = ps[idx[i]] + cur + ps[n]-ps[idx[j]+1];
            if(val > ans)ans=val,l = idx[i],r = idx[j];
        }
    }
    
    cout<<l+1<<' '<<r+1<<endl;


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

