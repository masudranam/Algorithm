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

int a[N];
int n, l;

bool ok(int k){
    int s = 0;
    for(int i = 0, j = 0; i < n; i++){
        while(j < n && s < k){
            s += a[j];
            if(s < k && j - i + 1>= l) return false;
            j++;
        }
        if(j == n)return true;
        if(s < k)return false;
        if(j - i > l)return false;
        s -= a[i];
    }
    return true;
}


void solve(){
    cin >> n >> l, n--;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l1 = 0, r1 = M;

    while(r1 - l1 > 0){
        int m = (l1 + r1 + 1) / 2;
        if(ok(m))l1 = m;
        else r1 = m - 1;
    }
    cout << l1 << endl;
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

