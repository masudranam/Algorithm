#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
<<<<<<< HEAD
 
=======

>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
<<<<<<< HEAD
    map<int,vector<int>> id;
    id[0].push_back(0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ^= a[i-1];
        id[a[i]].push_back(i);
    }
    

    while(q--){
        int l, r;
        cin >> l >> r;
        //cout << l << ' ' << r << '\n';
        if(a[l-1] == a[r])cout << "Yes\n";
        else{
            auto R = *--lower_bound(id[a[l-1]].begin(),id[a[l-1]].end(),r);
            auto L = *lower_bound(id[a[r]].begin(), id[a[r]].end(),l);
         
           
            if(R > L)cout << "Yes\n";
            else cout << "No\n";
        }
    }
    cout << '\n';

=======

    map<int,vector<int>>mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        int x = a[i];
        a[i] ^= (a[i-1]);
        if(x)mp[a[i]].push_back(i);
    }

    while(q--){
        int l, r; 
        cin >> l >> r;
        if((a[r]^a[l-1]) == 0){
            cout << "YES\n";continue;
        }
        cout << (a[r]^a[l]) <<'\n';
        auto &v = mp[a[r]];
        print(v);
        auto it =upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),l);
        if(it > 1)cout << "YES\n";
        else cout << "NO\n";
    }
    cout << '\n';
>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
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
<<<<<<< HEAD
=======

>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
