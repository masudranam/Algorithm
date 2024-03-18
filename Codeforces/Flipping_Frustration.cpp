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

int gcd(int a,int b,int& x,int& y) {
    if(!b) {
        x=1,y=0;
        return a;
    }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

bool any_solution(int a, int b, int c, int &x0, int &y0) {
   int g = gcd(abs(a), abs(b), x0, y0);
   if (c % g) {
   return false;
   }
   x0 *= c / g;
   y0 *= c / g;
   if (a < 0) x0 = -x0;
   if (b < 0) y0 = -y0;
   return true;
}

void shift(int & x, int & y, int a, int b, int cnt) {
   x += cnt * b;
   y -= cnt * a;
}

int n, t, l, r;

bool ok(int x, int y, int page){
    if(x == 0 && y == 0) return true;
    int rem = n - page;
    int right = min(x, rem / r);
    if(right > 0) return ok(x - right, y, page + right*r);
    int left = min(y,page/l);
    if(left > 0) return ok(x, y - left, page - left*l);
    return false; // left and right equal 0 cannot move anywhere
}


void solve(){
    cin >> n >> l >> r >> t;
    n--, t--;

    if(t == 0){
        cout << 0 << endl;
        return;
    }
    int x = 0, y = 0;

    int g = gcd(r,l,x,y);
    if(t % g){
        cout <<"uh-oh!\n";
        return;
    }

    x *= (t / g), y *= (t / g);

    /*
    we can shift x && y
    shift x - > x + k*(l / g)
    shift y - > y - k*(r / g)
    y (left turn) must be <= 0 && x (right turn) must be >= 0    
    y - k*r/g <= 0 ---> k >= y*g / r;
    x + k*l/g >= 0 ---> k >= -x*g /l;
    k >= max(-x*g/l, y*g/r);
    */

   int k = ceil(max((-1.0*x*g/l),(1.0*y*g/r)));
   
   // shift x && y

   x += (l*k / g), y -= (r * k / g);

   //cheeck if x right move cross page n or turning y left shift go neg

   if(ok(x, -y, 0)){
    cout << x - y << endl;
   }else{
    cout <<"uh-oh!\n";
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

