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


struct P {
   double x=0, y=0;
   void read() { cin >> x >> y; }
};

double eucl(P a, P b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double man(P a, P b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
double A, B, C;

P get(P a, int is_x){
    if(is_x)return {a.x, (-A*a.x - C) / B};
    else return {(-B*a.y - C) / A, a.y};
}

void solve(){
    cin >> A >> B >> C;
    P a, b;
    a.read(), b.read();

    if(A == 0 || B == 0){
        cout<< fixed << setprecision(10) << man(a,b) << endl;
        return;
    }

    double ans = man(a,b);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            P p = get(a,i), q = get(b,j);
            ans = min(ans,man(a,p) + eucl(p,q) + man(b,q));
        }
    }
    cout << fixed << setprecision(10) << ans <<endl;
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

