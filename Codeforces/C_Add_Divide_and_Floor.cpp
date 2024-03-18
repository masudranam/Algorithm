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

    int mx = 0;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(a[i],mx);
    }
    int ans = 0, mx1 = mx;
    while(mx1 > 0)ans++,mx1/=2;
    int ans1 = 0;

    vector<int> b;

    while(mx > 0){
        int tmp = 0;
        int cnt = 0;
        sort(all(a));

        if(a[0] == a.back())break;
        for(int i = 0; i < n; i++){
            cnt += (a[i]%2 == 0);
        }
        if(cnt == n || cnt == 0){
            b.push_back(0);
            ans1++;
            for(auto &x: a)x/=2;
            continue;
        }

       tmp = a.back();
       
            for(int i = 0; i < n; i++){
                
                if(tmp % 2 == 0){
                    a[i] = (a[i]+1)/2;
                }else{
                    a[i] = (a[i]+2)/2;
                }
            }
           if(tmp%2 == 0)b.push_back(1);
            else b.push_back(2);
         mx = tmp;
         ans1++;
    }

    if(ans1 < ans){
        cout<<ans1<<endl;
        if(ans1 <= n && ans1){
           for(auto x: b)cout<<x<<' ';
           cout<<endl;
        }
    }else{
        cout<<ans<<endl;
        if(ans <= n){
            for(int i = 0; i < ans; i++)cout<<0<<' ';
            cout<<endl;
        }
    }

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

