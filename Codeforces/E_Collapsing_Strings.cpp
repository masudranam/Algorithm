#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 5e6 + 10;

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
            t[cur].cnt++;
        }
    }

  long long  int get(string s) {
        int cur=0;
        long long int cnt = 0;
        for(int i=0; i<sz(s); i++) {
            int to=s[i]-'a';
            if(!t[cur].nxt[to])return 2*cnt;
            cur=t[cur].nxt[to];
            //debug(t[cur].cnt);
            cnt += t[cur].cnt;
        }
        return 2*cnt;
    }

};

void solve(){
    int n;  cin >> n;
    vector<string> s(n);

    Trie trie;

    int cnt =  0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        cnt += sz(s[i]);
        trie.add(s[i]);
    }
    
   long long int ans = 0;

    for(int i = 0; i < n; i++){
        reverse(all(s[i]));
    long long int x = n*1ll*sz(s[i]) + cnt;
        ans += (x - trie.get(s[i]));
    }

    cout << ans <<endl;

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

