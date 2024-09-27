#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

bool ok(int k, string s){
    bool f = 1;
    for(int i = k; i < s.size(); i++){
        f &= (s[i] != s[i-k]);
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = s.size()-1; i >= 0 && s[i] == s[s.size()-1]; i--){
        cnt1++;
    }
    for(int i = 0; i < s.size() && s[i] == s[0]; i++){
        cnt2++;
    }
    return f && cnt1 == k && cnt2 == k;
}

void solve(){
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s;

    int cnt = 0;
    for(int i = n-1; i >= 0 && s[i] == s[n-1]; i--){
        cnt++;
    }

    if(cnt > k){
        cout << - 1 << '\n';
        return;
    }

    if(ok(k,s)){
        cout << n << '\n';return;
    }
    char c = s[0];
    cnt = 1;

    for(int i = 1; i < n; i++){
        if(c == s[i])cnt++;
        else{
           if(cnt == k){
            cnt = 1;
            c = s[i];
            continue;
           }
           if(cnt > k) i = i - k;

            t = s.substr(0,i);
            reverse(t.begin(),t.end());
            t = s.substr(i) + t;

            if(ok(k,t)){
                cout << i << '\n';
                return;
            }else{
                cout << - 1 << '\n';
                return;
            }
        }
    }
    if(cnt != k){
        cout << - 1 << '\n';
        return;
    }
    cout << n <<'\n';
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

