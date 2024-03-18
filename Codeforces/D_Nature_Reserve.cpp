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

const double eps = 1e-6;
const double PI = acos (-1.0);

struct P {
   double x=0, y=0;
   void read() { cin >> x >> y; }
};

P p[N];
int n;

double d(double x1, double y1, double x2, double y2){
    double dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return sqrt(dist);
}


bool ok(double x, double R){
    double dist = 0;
    
    for(int i = 0; i < n; i++){
        double d1 = d(x,R,p[i].x,p[i].y);
        dist = max(dist,d1);
    }
    return dist <= R;
}

double getR(double x){
    double l = 0, r = 100;
    int cnt = 50;

    while(r-l > eps && cnt--){
        double m = (l+r)/2;
        if(ok(x,m))r = m;
        else l = m;
    }
    return l;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        p[i].read();
    }

    double l = -10, r = 10, d = 0.05;
    double m = (l+r)/2;

    while(r-l > 0.001){
        double m = (l+r)/2;
        cout<<l<<' '<<m<<' '<<r<<endl;
        cout<<getR(m-d)<<' '<<getR(m)<<' '<<getR(m+d)<<endl;
        if(getR(m-d) > getR(m) && getR(m) > getR(m+d))l = m;
        else r = m;
    }
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

