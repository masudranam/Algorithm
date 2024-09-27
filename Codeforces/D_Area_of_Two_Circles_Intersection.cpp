#include<bits/stdc++.h>
using namespace std;

//#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
#define double long double

const int M = 1e9 + 7;
const int N = 2e5 + 10;

const double eps = 1e-9;
const double PI = acos(-1.0);

int sign(double x) {
    return (x > eps) - (x < -eps);
}

struct P {
    double x, y;

    P() {x = y = 0;}
    P(double x, double y):x(x),y(y) {}
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

    bool operator == (P a) const {return (sign(a.x - x) == 0 && sign(a.y - y) == 0);}
    bool operator  < (P a) const {return sign(a.x-x)==0? y<a.y:x<a.x;}
    bool operator  > (P a) const {return sign(a.x-x)==0? y>a.y:x>a.x;}
    bool operator != (P a) const {return !(*this == a);}
};

struct Line { // ax + by + c = 0
    double a, b, c;
    Line(){a = b = c = 0;}
    Line(double a, double b, double c):a(a),b(b),c(c){}
    Line(P p1, P p2){
        this->a = p2.y - p1.y;
        this->b = p1.x - p2.x;
        this->c = -(p2.y - p1.y) * p1.x - (p1.x - p2.x) * p1.y;
    }
};

struct circle{
    double r;
    P c;
    circle(P p, double r){
        this->r = r;
        c = p;
    }
    void print(){
        cout << "(x, y) = " << c.x << ',' << c.y << '\n';
        cout << "r = " << r << '\n';
    }
};

double norm(P p) {return sqrt(p.x * p.x + p.y * p.y);}
double arg(P p) {return atan2(p.y, p.x);}   //tan^-1(y/x) value of theta in radian
double dot(P a, P b) {return a.x * b.x + a.y * b.y;}
double dist(P a, P b) {return sqrt(dot(a - b, a - b));}
double cross(P a, P b) {return a.x * b.y - a.y * b.x;}
double cross2(P a, P b, P c) {return cross(b - a, c - a);} //Area of a triangle
int orientaion(P a, P b, P c) {return sign(cross(b - a, c - a));}
P perp(P a) {return P{-a.y, a.x};}
double deg_to_rad(double d) {return d * PI / 180.0;}
double rad_to_deg(double r) {return r * 180.0 / PI;}
double get_angle(P a, P b) {
    double costheta = dot(a, b) / norm(a) / norm(b);
    return acos(max((double) -1.0, min((double) 1.0, costheta)));
}

P rotateCCW(P p, double theta) { //rotate p by theta degree ccw w.r.t origin(0,0)
    double rad = deg_to_rad(theta);
    P res;
    res.x = (p.x*cos(rad)-p.y*sin(rad)), res.y = (p.x*sin(rad)+p.y*cos(rad));
    return res;
}

//rotate p by theta degree cw w.r.t origin(0,0)
P rotateCW(P p, double theta) { 
    double rad = deg_to_rad(theta);
    P res;
    res.x = (p.x*cos(rad)+p.y*sin(rad)), res.y = (-p.x*sin(rad)+p.y*cos(rad));
    return res;
}

//Finds a point from 'a' through 'b' with distance 'd'
P PointAlongLine(P a, P b, double d){
    return a + (((b-a) / sqrt(dot(b-a,b-a))) * d);
}

//Projects the point 'c' onto line through 'a' and 'b' (assuming a != b)
P ProjectPointToLine(P a, P b, P c){
    return a+(b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

//Projects point 'c' onto the line segment through 'a' and 'b'
P ProjectPointToSegment(P a, P b, P c){
    double r=dot(b-a,b-a);
    if(fabs(r)<eps) return a;
    r=dot(c-a, b-a)/r;
    if(r<0) return a;
    if(r>1) return b;
    return a+(b-a)*r;
}

//Computes distance from 'c' to the line segment between 'a' and 'b'
double DistanceFromPointToSegment(P a, P b, P c){
    return dist(c, ProjectPointToSegment(a, b, c));
}
 
//Computes minimum distance from a point 'p' to a line 'AB'
double DistToLine(P p, P A, P B){
    double scale=dot(p-A,B-A)/dot(B-A,B-A);
    P c;
    c.x=A.x+scale*(B.x-A.x);
    c.y=A.y+scale*(B.y-A.y);
 
    return dist(p, c);
}

//Computes minimum distance from a point 'p' to a line segment 'AB'
double DistToLineSegment(P p, P A, P B){
    P c;
    if(dot(B-A,p-A)<eps) return dist(p, A);
    if(dot(A-B,p-B)<eps) return dist(p, B);
    return DistToLine(p, A, B);
}

//Determine weather the two seg parallel or not
bool segParallel(P a, P b, P c, P d) {
    return abs(cross(a-b,c-d))  < eps;
}

//Determines if the lines from 'a' to 'b' and 'c' to 'd' are collinear or not
bool LinesCollinear(P a, P b, P c, P d){
    return segParallel(a, b, c, d) && fabs(cross(a-b, a-c))<eps && fabs(cross(c-d, c-a))<eps;
}

// Before calling this, check whether the line segments are parallel or not
// Determines whether the two line segments intersects or not.
bool SegmentsIntersect(P a, P b, P c, P d){
    if(LinesCollinear(a, b, c, d))    {
        if(dot(a, c)<eps || dot(a, d)<eps || dot(b, c)<eps || dot(b, d)<eps) return true;
        if(dot(c-a, c-b)>0 && dot(d-a, d-b)>0 && dot(c-b, d-b)>0) return false;
        return true;
    }
 
    if(cross(d-a, b-a)*cross(c-a, b-a)>0) return false;
    if(cross(a-c, d-c)*cross(b-c, d-c)>0) return false;
    return true;
}
 
//Computes intersection of the line passing through 'a' and 'b' with the line passing through 'c' and 'd'
P ComputeLineIntersection(P a, P b, P c, P d)
{
    double a1=a.y-b.y;
    double b1=b.x-a.x;
    double c1=cross(a, b);
    double a2=c.y-d.y;
    double b2=d.x-c.x;
    double c2=cross(c, d);
    double D=a1*b2-a2*b1;
    return P((b1*c2-b2*c1)/D, (c1*a2-c2*a1)/D);
}

//Computes center of the circle passing through the points 'a', 'b' and 'c'
P ComputeCircleCenter(P a, P b, P c){
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection(b, b+rotateCW(a-b,90), c, c+rotateCW(a-c,90));
}

//Computes intersection of the line through points 'a' and 'b' with the circle centered at 'c' with radius 'r'
vector<P> CircleLineIntersection(P a, P b, P c, double r)
{
    vector<P>ret;
    b=b-a;
    a=a-c;
    double A=dot(b, b);
    double B=dot(a, b);
    double C=dot(a, a)-r*r;
    double D=B*B-A*C;
 
    if(D<-eps) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+eps))/A);
    if(D>eps) ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}

//Computes intersection of the circle centered at 'c1' with radius 'r1' with the circle centered at 'c2' with radius 'r2'
vector<P> CircleCircleIntersection(P c1, P c2, double r1, double r2){
    vector<P>ret;
 
    double d=dist(c1, c2);
    if(d>r1+r2 || d+min(r1, r2)<max(r1, r2)) return ret;
 
    double x=(d*d-r2*r2+r1*r1)/(2.0*d);
    double y=sqrt(r1*r1-x*x);
 
    P v=(c2-c1)/d;
 
    ret.push_back(c1+v*x+rotateCCW(v,90)*y);
    if(y>0) ret.push_back(c1+v*x-rotateCCW(v,90)*y);
    return ret;
}

//Returns the perpendicular line of the line 'ab' which intersects with it at point 'c' in CCW direction
pair<P,P> GetPerpendicularLine(P a, P b, P c){
    return make_pair(rotateCCW(a-c,90)+c,rotateCCW(b-c,90)+c);
}

bool pointOnSeg(P p, P a, P b) { // If point p in the segement of ab
    if(dist(p,b) < eps || dist(p,a) < eps)
        return true;
    return (segParallel(p,a,p,b) && dot(p-a,p-b) < 0);
}

// Returns a parallel line of the line 'ab' in CCW direction with d distance from 'ab'
pair<P,P> GetParallelLine(P a, P b, double d){
    return make_pair(PointAlongLine(a, rotateCCW(b-a,90)+a, d), PointAlongLine(b, rotateCW(a-b,90)+b, d));
}

//Determine weather the pooint p on the polygon or not.
bool pointOnPloygon(P p, const vector<P> &points) {
    int n = points.size();
    for(int i = 0; i < n; i++) {
        if(pointOnSeg(p,points[i],points[(i+1)%n]))
            return true;
    }
    return false;
}

//Determine weather the point p inside the polygon or not.
bool pointInside(const P &p, const vector<P> &points) {
    int n = points.size();
    bool ok = false;

    for(int i = 0; i < n; i++) {
        int j = (i+1)%n;
        if((p.y < points[i].y != p.y < points[j].y)
                && (p.x < points[i].x + (points[j].x -
                                         points[i].x)*(p.y-points[i].y)/(points[j].y-points[i].y)))
            ok = !ok;
    }
    return ok;
}

bool ccw(P p, P q, P r) {
    return cross(q-p,r-p) < eps;
}

//Return the points of the convex polygon
vector<P> Convex_Hull(vector<P> points) {
    int n = points.size();
    sort(points.begin(), points.end());
    vector<P> hull;
    for(int rep = 0; rep < 2; rep++) {
        int s = hull.size();
        for(int i = 0; i < n; i++) {
            while((int)hull.size() >= s + 2) {
                P A = hull.end()[-2];
                P B = hull.end()[-1];
                P C = points[i];
                if(cross2(A,B,C) <= 0)
                    break;
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        hull.pop_back(); // comment this line if necessary
        reverse(points.begin(), points.end());
    }
    return hull;
}


Line pointToLine(P a, P b) {
    Line l;
    if(fabs(a.x-b.x) < eps)
        l.a = 1.0, l.b = 0.0, l.c = -a.x;

    else {
        l.a = -(a.y-b.y)/(a.x-b.x);
        l.b = 1.0;
        l.c = -(l.a*a.x)-a.y;
    }
    return l;
}

Line pointSlopeToLine(P p, double m) {
    Line l;
    l.a = -m, l.b = 1;
    l.c = -((l.a*p.x) + (l.b*p.y));
    return l;
}

bool areParallel(Line l1, Line l2) { //Two line are parallel or not
    return (fabs(l1.a - l2.a) < eps) && (fabs(l1.b - l2.b) < eps);
}

bool areSame(Line l1, Line l2) { //Two line same or not
    return areParallel(l1,l2) && (fabs(l1.c-l2.c) < eps);
}

bool areIntersect(Line l1, Line l2,P &p) {
    if(areParallel(l1,l2))return false;
    //solve system of 2 linear algebric eqn with 2 unknowns
    p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
    //special case: test for vertical line to avoid divison by zero
    if(fabs(l1.b) > eps)p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}

bool collinear(P p, P q, P r) { //retrurn true if r in the same line of pq
    return fabs(cross(q-p,r-p)) < eps;
}

P closestPoint(Line l, P p) { //Perpendicular to l and pass through p
    Line perp;
    P r;
    if(fabs(l.b) < eps) {
        r.x = -l.c, r.y = p.y;
        return r;
    }
    if(fabs(l.a) < eps) {
        r.x = p.x, r.y = -l.c;
        return r;
    }
    perp = pointSlopeToLine(p,1/l.a); //normal line
    //intersect lien l with this perp line
    // the intersection point is the closest point
    areIntersect(l,perp,r);
    return r;
}

double circle_circle_area(P p1,double r1, P p2,double r2){
   double d = dist(p1,p2);
    if(d > r1 + r2) return 0;
    if(r1 + d <= r2 || r2 + d <= r1){
        return acos(-1) * min(r1,r2)*min(r1,r2);
    }
    double alpha = 2.0 * acos((r1*r1 + d*d - r2*r2) / (2*r1*d));
    double beta = 2.0 * acos((r2*r2 + d*d - r1*r1) / (2*r2*d));
    double A1 = 0.5 * r1*r1 * (alpha - sin(alpha));
    double A2 = 0.5 * r2*r2 * (beta - sin(beta));
    return A1 + A2;
}


void solve(){
    P p1, p2;
    double r1, r2;
    p1.read(); cin >> r1;
    p2.read(); cin >> r2;
    cout <<fixed << setprecision(20) << circle_circle_area(p1,r1,p2,r2) << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

