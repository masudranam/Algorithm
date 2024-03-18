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
        if((p.y < points[i].y != p.y < points[j].y) && (p.x < points[i].x + (points[j].x - 
        points[i].x)*(p.y-points[i].y)/(points[j].y-points[i].y))){
            ok = !ok;
        }
    }
    return ok;
}

bool ccw(P p, P q, P r){
    return cross(q-p,r-p) < eps;
}

vector<P> convex_hull(vector<P> points){
    //--Incremental algorithm--
    //upper hull

    sort(points.begin(),points.end());
    stack<P> stk_up;
    stk_up.push(points[0]);
    stk_up.push(points[1]);
    for(int i = 2; i < sz(points); i++){
        while(sz(stk_up) >= 2){
            P p1, p2;
            p1 = stk_up.top();
            stk_up.pop();
            p2 = stk_up.top();
            if(ccw(points[i],p1,p2)){
                stk_up.push(p1);
                break;
            }
        }
        stk_up.push(points[i]);
    }
    //lower hull
    for(int i = 0; i < sz(points); i++){
        points[i].x = -points[i].x;
        points[i].y = -points[i].y;
    }

    sort(all(points));
    stack<P> stk_low;
    stk_low.push(points[0]);
    stk_low.push(points[1]);

    for(int i = 2; i < sz(points); i++){
        while(sz(stk_low) >= 2){
            P p1, p2;
            p1 = stk_low.top();
            stk_low.pop();
            p2 = stk_low.top();
            if(ccw(points[i],p1,p2)){
                stk_low.push(p1);
                break;
            }
        }
        stk_low.push(points[i]);
    }

    //Print ch cw order from leftmost point
    vector<P> CH;
    stk_low.pop();
    P  p;
    while(!stk_low.empty()){
        p = stk_low.top();
        p *= -1.0;
        CH.push_back(p);
        stk_low.pop();
    }
    stk_up.pop();
    while(!stk_up.empty()){
        CH.push_back(stk_up.top());
        stk_up.pop();
    }
    reverse(all(CH));
    return CH;
}

struct Line{ // ax + by + c = 0
  double a, b, c;
};

Line pointToLine(P a, P b){
  Line l;
  if(fabs(a.x-b.x) < eps){
    l.a = 1.0, l.b = 0.0, l.c = -a.x;
  }else{
    l.a = -(a.y-b.y)/(a.x-b.x);
    l.b = 1.0;
    l.c = -(l.a*a.x)-a.y;
  }
  return l;
}

Line pointSlopeToLine(P p, double m){
  Line l;
  l.a = -m, l.b = 1;
  l.c = -((l.a*p.x) + (l.b*p.y));
  return l;
}


bool areParallel(Line l1, Line l2){//Two line are parallel or not
  return (fabs(l1.a - l2.a) < eps) && (fabs(l1.b - l2.b) < eps);
}

bool areSame(Line l1, Line l2){//Two line same or not
  return areParallel(l1,l2) && (fabs(l1.c-l2.c) < eps);
}

bool areIntersect(Line l1, Line l2,P &p){
  if(areParallel(l1,l2))return false;
  //solve system of 2 linear algebric eqn with 2 unknowns
  p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
  //special case: test for vertical line to avoid divison by zero
  if(fabs(l1.b) > eps)p.y = -(l1.a*p.x + l1.c);
  else p.y = -(l2.a*p.x + l2.c);
  return true;
}

bool collinear(P p, P q, P r){//retrurn true if r in the same line of pq
return fabs(cross(q-p,r-p)) < eps;
}

P closestPoint(Line l, P p){//Perpendicular to l and pass through p
  Line perp;
  P r;
  if(fabs(l.b) < eps){
    r.x = -l.c, r.y = p.y;
    return r;
  }
  if(fabs(l.a) < eps){
    r.x = p.x, r.y = -l.c;
    return r;
  }
  perp = pointSlopeToLine(p,1/l.a); //normal line
  //intersect lien l with this perp line
  // the intersection point is the closest point
  areIntersect(l,perp,r);
  return r;
}

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

