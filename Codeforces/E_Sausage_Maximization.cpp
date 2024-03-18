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
    int nxt[2];
    int cnt;
    Node() {
        fill(nxt,nxt+2,0);
        cnt = 0;
    }
};

struct Trie {
    vector<Node>t;
    Trie() {
        t.push_back(Node());
    }

    void add(vector<int> bit) {
        int cur = 0;
        for(int i = 0; i < 45; i++) {
            int to = bit[i];
            if(!t[cur].nxt[to]) {
                t[cur].nxt[to]=sz(t);
                t.push_back(Node());
            }
            cur=t[cur].nxt[to];
            t[cur].cnt++;
        }
    }

    void ers(vector<int> bit){
        int cur = 0;
        for(int i = 0; i < 45; i++){
            int to = bit[i];
            cur = t[cur].nxt[to];
            t[cur].cnt--;
        }
    }

    int get(vector<int> bit) {
        int cur=0, ans = 0;

        for(int i=0; i < 45; i++) {
            int to = !bit[i];
            if(!t[cur].nxt[to]){
                cur = t[cur].nxt[!to];
                if(!to)ans |= (1ll<<(44-i));
            }else{
                cur = t[cur].nxt[to];
                if(to) ans |= (1ll<<(44-i));
            }
        }
        return ans;
    }

};

vector<int> bin(int x){
    vector<int> bit(45);
    int i = 44;
    while(x){
        bit[i--] = (x&1);
        x /= 2;
    }
    return bit;
}

void solve(){
    Trie t;
    
    int n; cin >> n;
    vector<int> a(n),b(n);
    int cur = 0;
    t.add(bin(cur));

    for(int i = 0; i < n; i++){
        cin >> a[i];
        cur ^= a[i];
        b[i] = cur;
        t.add(bin(cur));
    }

    cur = 0;
    int ans = t.get(bin(cur));

    for(int i = n-1; i >= 0; i--){
        cur ^= a[i];
        t.ers(bin(b[i]));
        ans = max(ans,cur^t.get(bin(cur)));
    }

    cout<<ans<<endl;

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

