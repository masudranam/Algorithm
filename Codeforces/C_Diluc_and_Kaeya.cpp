#include <bits/stdc++.h>
using namespace std;

#define endl       '\n'
#define  ar        array
#define int        long long
#define pb         push_back
#define vi         vector<int>
#define FOR(a,b,n) for(int a=b;a<n;a++)
#define input(v)   for(auto &x: v)cin>>x
#define all(x)     (x).begin(),(x).end()
#define debug(x)   cout<<#x<<" "<<x<<endl;
#define print(v)   for(auto x: v)cout<<x<<" "
#define fast       ios_base::sync_with_stdio(false);\
cin.tie(NULL);cout.tie(NULL)

const int M=5;
const int N=1e5;
//int a[N],b[N],c[N],d[N];

pair<int,int> p(int a,int b){
int g=__gcd(a,b);
a/=g;b/=g;
return {a,b};
}


void solve(){
  int n;cin>>n;
  string s;cin>>s;
  int d=0,k=0;
  map<pair<int,int>,int> mp;

  for(char c: s){
    if(c=='D')d++;
    else k++;
    cout<<++mp[p(d,k)]<<" ";

  }
  cout<<endl;


}

main(void) {fast;
int t=1; cin>>t;
while(t--)solve();}