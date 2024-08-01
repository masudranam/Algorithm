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
    string s, t;
    cin >> s >> t;

    string b = string(n,'1');
    b[0] = b.back() = '0';

    for(int i = 1; i + 1 < n; i++){
        if(s[i-1] == '1')b[i] = '0';
    }
    for(int i = n-2; i > 0; i--){
        if(s[i+1] == '1'){
            b[i] = '0';
        }
    }
    for(int i = 0; i < n; i++){
        if(t[i] == '1') b[i] = '1';
    }

    string a = string(n,'1');
    a[0] = a.back() = '0';
    for(int i = 1; i + 1 < n; i++){
        if(b[i-1] == '0')a[i] = '0';
    }
    for(int i = n-2; i > 0; i--){
        if(b[i+1] == '0')a[i] = '0';
    }

    vector<int> ps(n);
    for(int i = 0; i < n; i++){
        if(s[i] == '1')a[i] = '1';
    }

    for(int i = 1; i < n; i++){
        ps[i] = (a[i] == '1');
    
        ps[i] += ps[i-1];
   
    }

    vector<int> nxt(n+1,n),prv(n,-1);
    prv[0] = -1;
    for(int i = 0; i < n; i++){
        if(i)prv[i] = prv[i-1];
        if(s[i] == '0')prv[i] = i;
    }
    for(int i = n-1; i >= 0; i--){
        nxt[i] = nxt[i+1];
        if(s[i] == '0')nxt[i] = i;
    }

    //cout << a <<'\n'<<b<< '\n';
    int q; cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r, l--, r--;
        if(nxt[l] > prv[r]){
            cout << r-l+1 << '\n';
            continue;
        }
        int res = 0;
        if(nxt[l] - l){
            res += (nxt[l] - l);
            l = nxt[l];
        }else{
            res += s[l] == '1';
            l++;
        }
        
        if(r - prv[r]){
            res += (r - prv[r]);
            r = prv[r];
        }else{
            res += s[r] == '1';
            r--;
        }
   // cout << l << ' ' << r <<' '<<res<<'\n';
        if(r-l <= 0){
            for(int i = l; i <= r; i++){
                res += s[i] == '1';
            }
            cout << res << '\n';
            continue;
        }
       
        res += ps[r] - ps[l-1];
        cout << res << '\n';
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

