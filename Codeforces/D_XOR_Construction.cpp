#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define ROHIT ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int 
#define pb push_back
#define ppb pop_back
#define lb lower_bound
#define up upper_bound
#define fo(i,a,b) for(ll i=a; i<=b; i++)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define sort0(v) sort(all(v))
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define py {cout<<"YES"<<endl; return;}
#define pn {cout<<"NO"<<endl; return;}
#define c(v,s) count(v.begin(),v.end(),s)
#define sum(v) accumulate(v.begin(),v.end(),(ll)0)
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
 
void _print(ll t) {cerr<<t;}
void _print(int t) {cerr<<t;}
void _print(string t) {cerr<<t;}
void _print(char t) {cerr<<t;}
void _print(double t) {cerr<<t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
ll mod=1000000007;
ll mod2=998244353;
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll lcm(ll a,ll b) {return (a/__gcd(a,b))*b;}
bool isprime(ll n){ if(n<=1) return false; if(n<=3) return true; if(n%2==0 || n%3==0) return false; for(ll i=5; i*i<=n; i+=6){ if(n%i==0 || n%(i+2)==0) return false; } return true;}
unsigned ll power(ll x,ll y,ll p){unsigned ll res=1; x=x%p; while (y>0){ if(y&1) res=(res*x)%p;  y=y>>1;   x=(x*x)%p;  } return res%p;}
ll p(ll x,ll y){ll res=1;while (y>0){  if(y&1) res=(res*x); y=y>>1;  x=(x*x);} return res;}
ll modInverse(unsigned ll n,ll p){ return power(n,p-2,p);}
ll ncr(ll n,ll r,ll p){ if(n<0 || r>n) return 0; else if(r==0 || r==n) return 1; ll fac[n+1]; fac[0]=1; for(int i=1; i<=n; i++) fac[i]=(fac[i-1]*i)%p; return (fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r],p)%p)%p;}
ll factorial(ll n,ll p){ ll cnt=1; for(int i=1; i<=n; i++) { cnt*=i; cnt%=p;} return cnt%mod;}
bool sortbysec(const pair<ll,ll>& a,const pair<ll,ll>& b) {
    if(a.ff==b.ff) return a.ff<b.ff;
    else return a.ff>b.ff;
}
void computeLPSArray(string pat, ll M, ll lps[]){ll len = 0,i = 1;lps[0] = 0; while (i < M){if (pat[i] == pat[len]) len++,lps[i] = len,i++;else {if (len != 0) len = lps[len - 1];else lps[i] = len,i++;}}}
ll ispalindrome(string s) {for(ll i=0; i<(ll)s.size(); i++) {if(s[i]!=s[s.size()-i-1]) return 0;} return 1;}
void specialprimefactor(){int N=1e3;vector<ll>spf(N+1);fo(i,1,N) spf[i]=i;for(int i=2; i<=sqrt(N); i++){if(spf[i]==i){for(int j=i*i; j<=N; j+=i){if(spf[j]>i) spf[j]=i;}}}}
ll constructST(vll& v,ll l,ll r,ll u,vll& st){if(l==r) return st[u]=v[l];ll mid=(l+r)/2;return st[u]=constructST(v,l,mid,2*u+1,st)+constructST(v,mid+1,r,2*u+2,st);}
ll getsum(ll u,ll curl,ll curr,ll reql,ll reqr,vll& st){if(reql<=curl && reqr>=curr) return st[u];if(curr<reql || curl>reqr) return 0;ll mid=(curl+curr)/2;return getsum(2*u+1,curl,mid,reql,reqr,st)+getsum(2*u+2,mid+1,curr,reql,reqr,st);}
void update(vll& st,int v,int tl,int tr,int pos,int new_val){if(tl==tr){st[v]=new_val;}else{int tm=(tl+tr)/2;if (pos <= tm) update(st,v*2+1, tl, tm, pos, new_val);else update(st,v*2+2,tm+1,tr,pos,new_val);st[v]=st[v*2+1]+st[v*2+2];}}
vll dijkstra(vector<vector<pll>>& graph,ll src){ll n=graph.size()-1;vll distance(n+1);fo(i,1,n) distance[i]=1e17;distance[src]=0;set<pll>s;fo(i,1,n) s.insert({distance[i],i});vll visited(n+1);while(s.size()){auto x=*s.begin();ll u=x.ss;s.erase(x);visited[u]=1;for(auto neighbor:graph[u]) {ll v=neighbor.ff,d=neighbor.ss;if(distance[u]+d<distance[v]){if(!visited[v])s.erase({distance[v],v});distance[v]=distance[u]+d;if(!visited[v])s.insert({distance[v],v});}}}return distance;}

//------------------------------------------------------------DSU-------------------------------------------------//
vll parent;
vll size_of;
void create_dsu(ll n){parent.clear();size_of.clear();parent.resize(n);size_of.resize(n);fo(i,0,n-1) parent[i]=i;}
ll find(ll u){if(u==parent[u]) return u;return parent[u]=find(parent[u]);}
void union_bypath(ll u,ll v){ll x=parent[u],y=parent[v];if(x==y) return ;if(size_of[x]>size_of[y]) swap(x,y);parent[x]=y;size_of[y]=max(size_of[y],size_of[x]+1);}
//------------------------------------------------------------------DSU------------------------------------------------//




void solve()
{       
    

    
    ll n; cin >> n;

    vll v(n);

    fo(i,1,n-1) cin >> v[i];

    vll ans(n);

    for(int j = 0; j <= 30; j++ ){
        ll z=1,tmp=0;
        for(int i = 1; i < n; i++){
            tmp^=(v[i]&(1<<j));
            if(!tmp) z++;
        }
        if(z>=ceil_div(n,2)){
            tmp=0;
            for(int i = 1; i < n; i++){
                tmp^=((v[i]&(1<<j))!=0);
                if(tmp) ans[i] += p(2,j);
            }
        }else{
            tmp =  1;
            ans[0] += p(2,j);
            for(int i = 1; i < n; i++){
                tmp^=((v[i]&(1<<j))!=0);
                
                if(tmp) ans[i] += p(2,j);
            }
        }
    }

    fo(i,0,n-1) cout << ans[i] << " ";
    


    
 
} 


 
 
// -----------------------------------------------------------3125-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main(){
    ROHIT;
    // pre();
    ll t=1;
    // cin>>t;



    


    cout<<setprecision(3);
    for(int i=1; i<=t; i++){
        // cout<<"Case "<<i<<": ";
        
       solve();
    }
    
    return 0;
}