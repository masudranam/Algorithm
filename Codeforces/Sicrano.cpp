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

const double eps = 1e-9;
const double PI = acos (-1.0);

   int sign (double x) {
      return (x > eps) - (x < -eps);
   }

struct P {
   double x, y;

   P(){x = y = 0;}
   P(double x, double y):x(x),y(y){} 
   void read() { cin >> x >> y; }
   
   P operator + (const P& b) const { return P{x + b.x, y + b.y};}
   P operator - (const P& b) const { return P{x - b.x, y - b.y};}
   P operator / (const P& b) const { return P{x / b.x, y / b.y};}
   P operator * (const P& b) const { return P{x * b.x, y * b.y};}
   P operator + (const double k) const { return P{x + k, y + k};}
   P operator - (const double k) const { return P{x - k, y - k};}
   P operator * (const double k) const { return P{x * k, y * k};}
   P operator / (const double k) const { return P{x / k, y / k};}

   void operator += (const P& b) { x += b.x; y += b.y; }
   void operator -= (const P& b) { x -= b.x; y -= b.y; }
   void operator *= (const P& b) { x *= b.x; y *= b.y; }
   void operator /= (const P& b) { x /= b.x; y /= b.y; }
   void operator += (const double k) { x += k; y += k; }
   void operator -= (const double k) { x -= k; y -= k; }
   void operator *= (const double k) { x *= k; y *= k; }
   void operator /= (const double k) { x /= k; y /= k; }

   bool operator == (P a) const {return (sign (a.x - x) == 0 && sign (a.y - y) == 0);}
   bool operator  < (P a) const {return sign(a.x-x)==0? y<a.y:x<a.x;}
   bool operator  > (P a) const {return sign(a.x-x)==0? y>a.y:x>a.x;}
   bool operator != (P a) const {return ! (*this == a);}
};

   double norm(P p) {return sqrt (p.x * p.x + p.y * p.y);}
   double arg(P p) {return atan2 (p.y, p.x);}  //tan^-1(y/x) value of theta in radian
   inline double dot (P a, P b) {return a.x * b.x + a.y * b.y;}
   inline double dist (P a, P b) {return sqrt (dot (a - b, a - b));}
   inline double cross (P a, P b) {return a.x * b.y - a.y * b.x;}
   inline double cross2 (P a, P b, P c) {return cross (b - a, c - a);}
   inline int orientaion (P a, P b, P c) {return sign (cross (b - a, c - a));}
   P perp (P a) {return P{-a.y, a.x};}
   double deg_to_rad (double d) {return d * PI / 180.0;}
   double rad_to_deg (double r) {return r * 180.0 / PI;}
   double get_angle (P a, P b) {
      double costheta = dot (a, b) / norm(a) / norm(b);
      return acos (max ( (double) -1.0, min ( (double) 1.0, costheta)));
   }

 P rotate(P p, double theta){ //rotate p by theta degree ccw w.r.t origin(0,0)
        double rad = deg_to_rad(theta);
        P res;
        res.x = (p.x*cos(rad)-p.y*sin(rad)), res.y = (p.x*sin(rad)+p.y*cos(rad));
        return res;
   }

bool segParallel(P a, P b, P c, P d){ 
    return abs(cross(a-b,c-d))  < eps;
}

bool pointOnSeg(P p, P a, P b){ // If point p in the segement of ab
    if(dist(p,b) < eps || dist(p,a) < eps){
        return true;
    }
    return (segParallel(p,a,p,b) && dot(p-a,p-b) < 0);
}


void solve(){
    int n, m;
    cin >> n >> m;

    P p[n];
    for(int i = 0; i < n; i++){
        p[i].read();
    }

    for(int i = 0; i < m; i++){
        P a, b;
        a.read(),b.read();
        int ans = 0;
        for(int j = 0; j < n; j++){
          if(pointOnSeg(p[j],a,b))ans++;
        }
        cout<<ans<<endl;
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

