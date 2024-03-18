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
const int N = 2e5 + 10, K = 30;

struct Node {
    int nxt[2];
    int cnt;
    Node() {
        fill(nxt,nxt+2,0);
        cnt=0;
    }
};

vector<int> bin(int x){
    vector<int> b(K+1);
    for(int i = 0; i <= K; i++){
        b[i] = ((x&(1<<i)) != 0);
    }
    return b;
}

struct Trie {
    vector<Node>t;
    Trie() {
        t.push_back(Node());
    }

    void add(vector<int> b) {
        int cur = 0;
        for(int i = K; i >= 0; i--) {
            int to = b[i];
            if(!t[cur].nxt[to]) {
                t[cur].nxt[to]=sz(t);
                t.push_back(Node());
            }
            cur=t[cur].nxt[to];
        }
        t[cur].cnt++;
    }

    int get(vector<int> b) {
        int cur=0, ans = 0;
        for(int i = K; i >= 0; i--) {
            int to=b[i]^1;
            if(!t[cur].nxt[to]){
                to ^=1;
            }else{
                ans += (1<<i);
            }
            cur=t[cur].nxt[to];
        }
        return ans;
    }
};



void solve(){
    int n; cin >> n;
    vector<int> a(n-1);

    Trie trie;
    for(auto &x: a)cin >> x;
    int cur = 0;
    for(int i = 0; i < n - 1; i++){
        cur ^= a[i];
        trie.add(bin(cur));
    }
    
    int b = -1;
    for(int i = 0; i < n; i++){
        if(trie.get(bin(i)) < n){
            b = i; break;
        }
    }
    cout<<b<<' ';
    for(int i = 0; i < n-1; i++){
        b = b^a[i];
        cout<<b<<' ';
    }
    cout<<endl;
    
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

