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
const int N = 1e6 + 100;
 
string t;
int n,node,par[N],d[N],pl[N],sl[N],trie[N][150];
int nxt[N][150],ans[N],vis[N],a[N],lev[N],mn[N];
vector<int>tr[N],qr;
int cnt[N];
 
 
void ins(string &s){
    int cur=0;
    for(auto it: s){
        int c=it;
        if(!trie[cur][c]){
            trie[cur][c]=++node;
            d[node]=d[cur]+1;
            par[node]=cur;
            pl[node]=c;
        }
        cur=trie[cur][c];
    }
    qr.push_back(cur);
}
 
void push_link(){
    queue<int>q;
    q.push(0);
    while(sz(q)){
        int v=q.front();
        q.pop();
        if(d[v]<=1)sl[v]=0;
        else{
            int u=sl[par[v]];
            int l=pl[v];
            while(u>0 && !trie[u][l])u=sl[u];
            if(trie[u][l])u=trie[u][l];
            sl[v]=u;
        }
        if(v!=0)tr[sl[v]].push_back(v);
        for(int i=0; i<150; i++)if(trie[v][i])q.push(trie[v][i]);
    }
}
 
int jump(int cur, int id){
    if(nxt[cur][id])return nxt[cur][id];
    int u=cur;
    while(cur>0 && !trie[cur][id])cur=sl[cur];
    if(trie[cur][id])cur=trie[cur][id];
    return nxt[u][id]=cur;
}
 
void Search(){
    int cur=0;
    for(int i=0; i<sz(t); i++){
        int c=t[i];
        while(cur>0 && !trie[cur][c]){
            cur=sl[cur];
        }
        cur=trie[cur][c];
        cnt[cur]++;
    }
}
 
void dfs(int u){
    vis[u]=1;
    for(auto v: tr[u]){
        if(!vis[v])dfs(v);
        cnt[u]+=cnt[v];
    }
}
 
void solve(){
  cin>>t;
  int n; cin>>n;
  for(int i=0; i<n; i++){
    string s;
    cin>>s;
    ins(s);
  }
  push_link();
  Search();
  for(int i=0; i<n; i++){
    if(!vis[qr[i]])dfs(qr[i]);
    cout<<cnt[qr[i]]<<endl;
  }
 
 
}
 
 
signed main() {
    ios_base::sync_with_stdio (0);
    cin.tie (0);
 
    int t = 1;    //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        //cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
 
 