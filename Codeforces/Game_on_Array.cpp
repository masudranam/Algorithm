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

    int odd = 0, even = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];

        if(i%2)even+=a[i];
        else odd += a[i];
    }

    if(n == 1){
        if(odd == 1)cout << "Bob\n";
        else "Alice\n";
        return;
    }

    if((even+odd) % 2){
        cout <<"Bob\n";return;
    }
    int mv = (even+odd)/2-1;

    if(even % 2){
        if(mv % 2 == 0)cout << "Bob\n";
        else cout <<"Alice\n";    
    }else{
        if(mv % 2 == 1)cout << "Bob\n";
        else cout <<"Alice\n";
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

