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
    
    set<string> s01,s10;
    int zero = 0, three = 0;
    string s[n];

    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(s[i][0] == '0' && s[i].back() == '1'){
            s01.insert(s[i]);
        }else if(s[i][0] == '1' && s[i].back() == '0'){
            s10.insert(s[i]);
        }else if(s[i].back() == '0')zero++;
        else three++;
    }

    if((sz(s01)+sz(s10) == 0) && zero && three){
        cout << -1 << endl; return;
    }

    vector<int> ans;

    if(sz(s01) > sz(s10)){
        for(int i = 0; i < n; i++){
            if(s[i][0] == '0' && s[i].back() == '1'){
              string ss(s[i]);
              reverse(all(ss));  
              if(s10.find(ss) == s10.end())ans.push_back(i+1);
            }
            
        }
    }else{
        for(int i = 0; i < n; i++){
            if(s[i][0] == '1' && s[i].back() == '0'){
                string ss(s[i]); reverse(all(ss));

                if(s01.find(ss) == s01.end()){
                    ans.push_back(i+1);
                }
            }
        }
    }

    int x = abs(sz(s01) - sz(s10))/2;
    cout << x << endl;
    for(int i = 0; i < x; i++){
        cout << ans[i] <<' ';
    }
    cout << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

