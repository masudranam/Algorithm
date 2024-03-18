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
    vector<int> a(n), b(n);

    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    set<ar<int,4>> sa,sb;

    for(int i = 0; i < n; i++){
        sa.insert({a[i]+b[i],a[i],b[i],i});
        sb.insert({a[i]+b[i],b[i],a[i],i});
    }


    int A = 0, B = 0, f = 1;

    while(sz(sa) > 0){
       if(f&1){
            ar<int,4> p = *sa.rbegin();
            //debug(p[3]);
            sa.erase(--sa.end());
            A += p[1]-1;
            swap(p[1],p[2]);
            sb.erase(p);
       }else{
        ar<int,4> p = *sb.rbegin();
        //debug(p[3]);
        sb.erase(--sb.end());
        B += p[1]-1;
        swap(p[1],p[2]);
        sa.erase(p);
       }
       f++;
    }

    cout<< A - B << endl;
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

