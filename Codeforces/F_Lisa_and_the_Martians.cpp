#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int ai, bi, res_x, res;
int a[N];

void get(vector<int> id, int k, int x, int cur){
    if(id.size() <= 1)return;
    if(k < 0){
        if(res < cur){
            ai = id[0];
            bi = id[1];
            res = cur;
            res_x = x;
        }
        return;
    }
    vector<int> A, B;
    for(int i = 0; i < id.size(); i++){
        if(a[id[i]] & (1 << k))A.push_back(id[i]);
        else B.push_back(id[i]);
    }
    if(A.size() == 1 && B.size() == 1){
        get(id, k - 1, x, cur);
        return;
    }
    get(A, k - 1, x, cur | (1 << k));
    get(B, k - 1, x | (1 << k) , cur | (1 << k));
}

void solve(){
    int n; cin >> n;
    int k; cin >> k;

    vector<int> id;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        id.push_back(i);
    }
    res = -1;
    get(id, k - 1, 0, 0);
    cout << ai + 1 << ' ' << bi + 1 <<' '<< res_x << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
