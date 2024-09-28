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

struct Node {
    int nxt[26];
    int cnt;
    Node() {
        fill(nxt,nxt+26,0);
        cnt=0;
    }
};

struct Trie {
    vector<Node>t;
    Trie() {
        t.push_back(Node());
    }

    void add(string s) {
        int cur = 0;
        for(auto c: s) {
            int to = c-'a';
            if(!t[cur].nxt[to]) {
                t[cur].nxt[to]=sz(t);
                t.push_back(Node());
            }
            cur=t[cur].nxt[to];
        }
         t[cur].cnt++;
    }

    int get(string s) {
        int cur=0;
        for(int i=0; i<sz(s); i++) {
            int to=s[i]-'a';
            if(!t[cur].nxt[to])return 0;
            cur=t[cur].nxt[to];
        }
        return t[cur].cnt;
    }

};

void solve(){
    string s; cin >> s;
    int n; cin >> n;

    Trie tr;
    for(int i = 0;i < n; i++){
        string t; cin >> t;
        tr.add(t);
    }
    int m = sz(s);
    vector<int> dp(m+1,0);
    dp[m] = 1;

    for(int i = m-1; i >= 0; i--){
        int cur = 0;
        for(int j = i; j < m; j++){
            if(!tr.t[cur].nxt[s[j]-'a'])break;
            cur = tr.t[cur].nxt[s[j]-'a'];
            if(tr.t[cur].cnt){
                dp[i] = (dp[i]+dp[j+1])%M;
            }
        }
    }
    cout<<dp[0]<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

