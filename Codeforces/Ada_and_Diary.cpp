#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M =100000000003ll;
const int N = 2e5 + 10;

void solve(){
    vector<int> a(6);
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5]){
    map<int,set<int>>st;
    int mn = 1000;
    for(int i = 1; i < 5; i++){
        if(a[i-1])mn = min(mn,a[i]/a[i-1]);
    }
    for(int i = 0; i < 5; i++){
        for(int x = 0,cnt = min(mn+5,100ll); x*a[i] <= a[i+1] && cnt--; x++){
            st[x].insert(a[i+1]-x*a[i]);
        }
    }
    int baire = 0;
    for(auto it: st){
        if(sz(it.second) != 1)continue;
        int f = it.first, s = (*it.second.begin());
        bool ok = 1;
        for(int i = 0; i < 5; i++){
            ok &= (f*a[i]+s == a[i+1]);
        }
        if(ok){
            cout<<(a.back()*f+s)%M<<endl;
            baire = 1;break;
        }
    }
    if(baire)continue;

    cout<<(a.back()+a[1])%M<<endl;
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

