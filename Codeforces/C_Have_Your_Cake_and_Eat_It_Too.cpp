#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i] = a[i-1] + x; 
    }
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        b[i] = b[i-1] + x;
    }
    int tot = 0;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        c[i] = c[i-1] + x;
        tot += x;
    }
    tot = (tot + 2) / 3;

     auto it = lower_bound(a.begin(),a.end(), tot) - a.begin();
     auto it1 = lower_bound(b.begin(),b.end(), b[it] + tot) - b.begin();
     if(it1 < n && c[n] - c[it1] >= tot){
        cout << 1 <<' ' << it <<' ' << it+1 <<' ' << it1 <<' ' << it1+1 <<' ' << n << '\n';
        return;
     }
     it1 = lower_bound(c.begin(),c.end(), c[it] + tot) - c.begin();
      if(it1 < n && b[n] - b[it1] >= tot){
        cout << 1 <<' ' << it <<' ' << it1+1 <<' ' << n <<' ' << it+1 <<' ' << it1 << '\n';
        return;
     }




      it = lower_bound(b.begin(),b.end(), tot) - b.begin();
      it1 = lower_bound(a.begin(),a.end(), a[it] + tot) - a.begin();
      //cout << it <<' ' << tot <<'\n';
     // print(b);
     if(it1 < n && c[n] - c[it1] >= tot){
        cout << it+1 <<' ' << it1 <<' ' << 1 <<' ' << it <<' ' << it1+1 <<' ' << n<< '\n';
        return;
     }
     it1 = lower_bound(c.begin(),c.end(), c[it] + tot) - c.begin();
      if(it1 < n && a[n] - a[it1] >= tot){
        cout << it1+1 <<' ' << n <<' ' << 1 <<' ' << it <<' ' << it+1 <<' ' << it1 << '\n';
        return;
     }





       it = lower_bound(c.begin(),c.end(), tot) - c.begin();
       it1 = lower_bound(b.begin(),b.end(), b[it] + tot) - b.begin();
     if(it1 < n && a[n] - a[it1] >= tot){
        cout << it1+1 <<' ' << n <<' ' << it+1 <<' ' << it1 <<' ' << 1 <<' ' << it << '\n';
        return;
     }
     
     it1 = lower_bound(a.begin(),a.end(), a[it] + tot) - a.begin();
      if(it1 < n && b[n] - b[it1] >= tot){
        cout << it+1 <<' ' << it1 <<' ' << it1+1 <<' ' << n <<' ' << 1 <<' ' << it << '\n';
        return;
     }
   

    cout << "-1\n";

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
