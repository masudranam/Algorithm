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

bool ok(string s){
    for(int i = 0; i < sz(s)/2; i++){
        if(s[i] != s[sz(s)-i-1])return false;
    }
    return true;
}

void solve(){
    int n, k;
    cin >> n >> k;
    map<string,vector<int>>mp,pal;

    for(int i = 0; i < n; i++){
        string s;cin >> s;
        int x; cin >> x;
        if(ok(s))pal[s].push_back(x);
        else
        mp[s].push_back(x);
    }

    for(auto &it: mp){
        sort(all(it.second));
    }

    for(auto &it: pal){
        sort(all(it.second));
    }

    map<string,vector<int>>tp = mp;

    int res = 0;

    for(auto it: mp){
        string s = it.first;
        reverse(all(s));
        vector<int> v = it.second, v1;
        if(tp.find(s) != tp.end())v1 = tp[s];

        for(int i = sz(v)-1, j = sz(v1)-1; i>=0 && j >= 0 ; i--,j--){
            if(v[i]+v1[j]>=0){
                res += (v[i]+v1[j]);
            }else break;
        }
    }
    res /= 2;

    int tmp = 0,mx = 0;

    for(auto it: pal){
        vector<int> v = it.second;
        for(int i = sz(v)-1; i > 0; i -= 2){
            if(v[i]+v[i-1] >= 0)tmp += (v[i]+v[i-1]);
            else break;
        }
    }

    for(auto it : pal){
        int cur = tmp;
        vector<int> v = it.second;
        for(int i = sz(v)-1; i > 0; i -= 2){
            if(v[i]+v[i-1] >= 0)cur -= (v[i]+v[i-1]);
            else break;
        }
        if(v.back() >= 0){
        cur += v.back();
        v.pop_back();
        }
        

        for(int i =sz(v)-1; i > 0; i-=2){
            if(v[i]+v[i-1]>=0)cur += (v[i]+v[i-1]);
            else break;
        }
        
        mx = max(mx,cur);
    }
    mx = max(mx,tmp);
    cout<<res + mx<<endl;
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

