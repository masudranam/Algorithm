#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
//#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;
 
struct Node {
    int nxt[2];
    int cnt;
    Node() {
        fill(nxt,nxt+2,0);
        cnt=0;
    }
};

struct Trie {
    vector<Node>t;
    Trie() {
        t.push_back(Node());
    }
    void add(int x) {
        int cur = 0;
        for(int i = 30; i >= 0; i--) {
            int to = (x >> i) & 1;
            if(!t[cur].nxt[to]) {
                t[cur].nxt[to]=t.size();
                t.push_back(Node());
            }
            t[cur].cnt++;
            cur=t[cur].nxt[to];
        }
         t[cur].cnt++;
    }

    int get(int x, int k) {
        int cur=0, res = 0;
        for(int i = 30; i >= 0; i--) {
            int to= ( x >> i) & 1;
            if((k >> i) & 1){
                if(t[cur].nxt[to^1]){
                    cur = t[cur].nxt[to^1];
                }else return res;
            }else{
                if(t[cur].nxt[to^1]){
                    res += t[t[cur].nxt[to^1]].cnt;
                }
                if(t[cur].nxt[to]){
                    cur = t[cur].nxt[to];
                }else return res;
            }
        }
        res += t[cur].cnt;
        return res;
    }
};

void solve(){
    int n; cin >> n;
    int k; cin >> k;

    Trie trie;
    trie.add(0);

  long long int res = 0, s = 0;
   for(int i = 0; i < n; i++){
    
    int x; cin >> x;
    s ^= x;
    trie.add(s);
    res += trie.get(s,k);
   }
   cout << res << '\n';
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
