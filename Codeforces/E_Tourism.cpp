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





int dfs(int u, int par)
{
	vis[u] = 1, dp[u] = val[u];
	bool check = 1;
	int cur = val[u];
	for(auto &it:g[u])
	{
		if(vis[it] && it != par)
			check = 0;
		else if(!vis[it])
		{
			check &= dfs(it, u);
			cur = max(cur, val[u] + dp[it]);
		}
	}
	dp[u] = cur;
	if(!check)
		canTake += val[u];
	else
		best = max(best, dp[u]);
	return check;
}
 

int n, m;
set<int> st[N];
vector<int> g[N];
int vis[N], w[N];

int bfs(int u){
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    int mx = 0;
    while(sz(q)){
        u = q.front();
        q.pop();
        for(auto v: g[u]){
            if(vis[v])continue;
            vis[v] = 1;
            w[v] += w[u];
            mx = max(mx,w[v]);
            q.push(v);
        }
    }
    return mx;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        st[u].insert(v);
        st[v].insert(u);
    }
    int s; cin >> s;

    queue<int> q;
    vector<int> nodes;

    for(int i = 1; i <= n; i++){
        if(sz(g[i]) == 1 && i != s)q.push(i);
    }

    while(sz(q)){
        int u = q.front();
        vis[u] = 1;
        q.pop();
        int v = *st[u].begin();
        st[v].erase(u);
        if(sz(st[v]) == 1 && s != v){
            q.push(v);
        }
    }
    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            ans += w[i];
            w[i] = 0;
        }else vis[i] = 0;
    }

    cout<<ans+bfs(s)<<endl;
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

