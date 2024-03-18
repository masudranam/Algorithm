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


void solve(){
    int n; cin >> n;
    int pw[50];
    map<int,int>mp;

    for(int i = 0; i < 40; i++){
        pw[i] = (1ll<<i);
        mp[pw[i]] = i;
    }

    vector<int> a(n);
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
        s += a[i];
    }
    if(s % n){
        cout<<"No\n";
        return;
    }
    s /= n;

    vector<int> cnt(40,0);

    for(int i = 0; i < n; i++){
        if(a[i] == s)continue;
        bool f = 0;
        if(a[i] > s){
            int d = a[i] - s;
            for(int j = 0; j < 40; j++){
                if(mp.find(d + pw[j]) != mp.end()){
                    cnt[mp[d+pw[j]]]--;
                    cnt[mp[pw[j]]]++;
                    f = 1;break;
                }
            }
        }else{
            int d = s - a[i];
            for(int j = 0; j < 40; j++){
                if(mp.find(d + pw[j]) != mp.end()){
                    cnt[mp[d + pw[j]]]++;
                    cnt[mp[pw[j]]]--;
                    f = 1;break;
                }
            }
        }
        if(f == 0){
            cout<<"No\n";return;
        }
    }
    for(int i = 0; i < 40; i++){
        if(cnt[i]){
            cout<<"No\n";return;
        }
    }
    cout<<"Yes\n";


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

