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

const double eps = 1e-12;
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
   double norm() {return sqrt (x * x + y * y);}
   double arg() {return atan2 (y, x);}

   inline double dot (P a, P b) {return a.x * b.x + a.y * b.y;}
   inline double dist (P a, P b) {return sqrt (dot (a - b, a - b));}
   inline double cross (P a, P b) {return a.x * b.y - a.y * b.x;}
   inline double cross2 (P a, P b, P c) {return cross (b - a, c - a);}
   inline int orientaion (P a, P b, P c) {return sign (cross (b - a, c - a));}
   P perp (P a) {return P{-a.y, a.x};}
   double deg_to_rad (double d) {return d * PI / 180.0;}
   double rad_to_deg (double r) {return r * 180.0 / PI;}
   double get_angle (P a, P b) {
      double costheta = dot (a, b) / a.norm() / b.norm();
      return acos (max ( (double) -1.0, min ( (double) 1.0, costheta)));
   }
};

bool segParallel(P a, P b, P c, P d){
    return abs(a.cross(a-b,c-d))  < eps;
}

bool pointOnSeg(P p, P a, P b){
    if(p.dist(p,b) < eps || p.dist(p,a) < eps){
        return true;
    }
    return (segParallel(p,a,p,b) && p.dot(p-a,p-b) < 0);
}

bool pointOnPloygon(const P &p, const vector<P> &points){
    int n = sz(points);
    for(int i = 0; i < n; i++){
        if(pointOnSeg(p,points[i],points[(i+1)%n])){
            return true;
        }
    }
    return false;
}

bool pointInside(const P &p, const vector<P> &points){
    int n = sz(points);
    bool ok = false;

    for(int i = 0; i < n; i++){
        int j = (i+1)%n;
        if((p.y < points[i].y != p.y < points[j].y) &&
        (p.x < points[i].x + 
        (points[j].x - 
        points[i].x)*
        (p.y-
        points[i].y)/
        (points[j].y-
        points[i].y))){
            ok = !ok;
        }
    }
    return ok;
}



void solve(){
    int n; 
    int m;
    cin >> n >> m;

    vector<P> points(n);
    for(int i = 0; i < n; i++){
        points[i].read();
        
    }
        while(m--){
        P p;
        p.read();
        if(pointOnPloygon(p,points)){
            cout<<"BOUNDARY\n";
        }else if(pointInside(p,points)){
            cout<<"INSIDE\n";
        }else{
            cout<<"OUTSIDE\n";
        }
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

