#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if(*max_element(a.begin(),a.end()) == -1){
        for(int i = 0; i < n; i++){
            cout << 1 + i%2 << ' ';
        }
        cout << '\n';return;
    }

    int L = 0, R = n-1;
    while(a[L] == -1)L++;
    while(a[R] == -1)R--;

    for(int i = L-1, f = 1; i >= 0; i--, f ^= 1){
        a[i] = (1 + f) * a[L];
    }
    for(int i = R+1, f = 1; i < n; i++, f ^= 1){
        a[i] = (1 + f) * a[R];
    }

   
    for(int i = L ; i + 1< R; ){
        int j = i + 1;
        while(j < R && a[j] == -1) j++;
        int l = i, r = j;
        while(l + 1 < r){
            if(a[l] >= a[r]){
                if(a[l] > 1)a[l+1] = a[l] / 2;
                else a[l+1] = 2*a[l];
                l++;
            }else{
                if(a[r] > 1) a[r-1] = a[r] / 2;
                else a[r-1] = 2 * a[r];
                r--;
            }
        }
        i = j;
    }

    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]/2 && a[i]/2 != a[i-1]){
            cout << "-1\n";
            return;
        }
    }

    print(a);
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
