#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
//#define int   long long int
 
const int M = 998244353;
const int N = 2e5 + 10;

template<const int mod, const int modPhi>
struct Mint {
  int v;
  Mint() { v = 0; }
  Mint(int x) { v = x % mod; if (v < 0) v += mod; }
  Mint(long long x) { v = x % mod; if (v < 0) v += mod; }
  friend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }
  friend bool operator!=(const Mint &a, const Mint &b) { return a.v != b.v; }
  friend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; }
  friend bool operator<=(const Mint &a, const Mint &b) { return a.v <= b.v; }
  friend bool operator>(const Mint &a, const Mint &b) { return a.v > b.v; }
  friend bool operator>=(const Mint &a, const Mint &b) { return a.v >= b.v; }
  Mint& operator+=(const Mint &a) { v += a.v; if (v >= mod) v -= mod; return *this; }
  Mint& operator-=(const Mint &a) { v -= a.v; if (v < 0) v += mod; return *this; }
  Mint& operator*=(const Mint &a) { v = (1LL * v * a.v) % mod; return *this; }
  Mint operator-() { return Mint(-v); }
  Mint& operator++() { return *this += 1; }
  Mint& operator--() { return *this -= 1; }
  friend Mint operator+(Mint a, const Mint b) { return a += b; }
  friend Mint operator-(Mint a, const Mint b) { return a -= b; }
  friend Mint operator*(Mint a, const Mint b) { return a *= b; }
  friend Mint min(Mint a, Mint b) { return (a < b ? b : a); }
  friend Mint max(Mint a, Mint b) { return (a > b ? a : b); }
  friend Mint pow(Mint a, long long b) {
    Mint res = 1;
    while (b > 0) {
      if (b & 1) {
        res *= a;
      }
      a *= a, b >>= 1;
    }
    return res;
  }
  friend Mint inv(const Mint &a) { return pow(a, modPhi - 1); }
  Mint operator/=(const Mint &a) { *this *= inv(a); return *this; }
  friend Mint operator/(Mint a, const Mint b) { return a /= b; }
  friend istream& operator>>(istream &in, Mint &a) { return in >> a.v; }
  friend ostream& operator<<(ostream &out, Mint a) { return out << a.v; }
};
using mint = Mint<M, M - 1>;


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
