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
   double x=0, y=0;
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


void solve(){
   


   
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

