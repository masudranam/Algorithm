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

map<int,int>mp;

int get(int x, int y){

    int d = x*x - 4*y;
    int a_b = sqrt(d);

    if(d < 0 || a_b*a_b != d){
        return 0;
    }

    if((a_b+x)%2 == 0){
        int a = (a_b+x)/2;
        int b = x - a;
        if(a*b != y)return 0;
        if(a == b)return (mp[a]*(mp[a]-1)/2);
        else return mp[a]*mp[b];
    }else if((x-a_b) % 2 == 0){
        int a = (x-a_b)/2;
        int b = x - a;
        if(a*b != y)return 0;
        if(a == b)return (mp[a]*(mp[a]-1)/2);
        else return mp[a]*mp[b];
    }
    return 0;
}

void solve(){
    int n; cin >> n;
    mp.clear();
    for(int i = 0; i <n; i++){
        int a; cin >> a;
        mp[a]++;
    }

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        cout << get(x,y) <<' ';
    }
    cout << endl;
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

