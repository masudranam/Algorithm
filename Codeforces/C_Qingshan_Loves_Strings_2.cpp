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
    int n;
    cin >> n;
    string s; cin >> s;

    bool ok = 1;
    for(int i = 0; i < n/2; i++){
        ok &= (s[i] != s[n-i-1]);
    }

    int one = 0, zero = 0;
    for(auto c: s){
        one += (c=='1');
        zero += (c=='0');
    }

    if(one != zero){
        cout<<"-1\n";return;
    }

    if(ok){
        cout<<0<<endl;
        return;
    }

    if(n&1){
      cout<<"-1\n";return;
    }
vector<int> ans;
 
    int cnt = n-1;

    for(int i = 0; i<cnt; i++){
        if(s[i] == s[cnt]){
            if(s[i] == '1'){
                s.insert(s.begin()+i,'0');
                s.insert(s.begin()+i+1,'1');
                cnt++;
                ans.push_back(i);
            }else{
            cnt++;
            s.insert(s.begin()+cnt,'0');
            ans.push_back(cnt); 
            }
        }else cnt--;
    }
   


    cout<<sz(ans)<<endl;
    print(ans);
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

