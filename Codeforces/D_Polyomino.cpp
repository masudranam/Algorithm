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

bool ok(int i, int j){
    return i >=0 && i < 4 && j >= 0 && j < 4;
}

void Rotate(vector<string> &v){
    vector<string> w = v;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            w[3-j][i] = v[i][j];
        }
    }
    v = w;
}

bool Possible(vector<vector<int>>&exist,const vector<string>&p, int di, int dj){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(p[i][j] == '#'){
                int ni = di + i, nj = dj + j;
                if(!ok(ni,nj))return false;
                if(exist[ni][nj])return false;
                exist[ni][nj] = 1;
            }
        }
    }
    return true;
}

void dfs(int i, const vector<vector<int>>&exist,const vector<vector<string>>&ps){
    if(i == 3){
        bool f = 1;
        for(int x = 0; x < 4; x++){
            for(int y = 0; y < 4; y++){
                f &= exist[x][y];
            }
        }
        if(f){
            cout<<"Yes\n";
            exit(0);
        }
        return;
    }
    for(int di = -3; di <= 3; di++){
        for(int dj = -3; dj <= 3; dj++){
            auto exist2 = exist;
            bool ff = Possible(exist2,ps[i],di,dj);
            if(ff)dfs(i+1,exist2,ps);
        }
    }
}

void solve(){
    vector<vector<string>>v(3,vector<string>(4));
    for(int i = 0; i < 3; i++){
        for(auto &s: v[i])cin >> s;
    }
    vector<vector<int>>vis(4,vector<int>(4,0));

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            dfs(0,vis,v);
            Rotate(v[2]);
        }
        Rotate(v[1]);
    }
cout<<"No\n";
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

