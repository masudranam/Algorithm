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

string s;
int n, k;

string get(){
    if(n % k )return "-1";
    vector<int> f(26);
    bool ok = true;
    for(int i = 0; i < 26; i++){
        f[i] = count(all(s),'a'+i);
        ok &= (f[i]%k == 0);
    }
    if(ok)return s;


    string ans = s;
    for(int i = n-1; i >= 0; i--){
        f[s[i]-'a']--;
        for(int ch = s[i]-'a' + 1; ch < 26; ch++){
            f[ch]++;
            int tot = 0;
            for(int j = 0; j < 26; j++){
                tot += (k-f[j]%k)%k;
            }
            if(i+1+tot<=n){
                ans[i++] = ('a'+ch);
                while(tot+i < n){
                    ans[i++] = 'a';
                }
               
                for(int j = 0; j < 26; j++){
                    int need = (k-f[j]%k)%k;
                    while(need--){
                        ans[i++] = ('a'+j);
                    }
                }
                return ans;
            }
            f[ch]--;
        }
    }
    return "-1";
}

void solve(){

    cin >> n >> k >> s;
    cout << get() << endl;
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

