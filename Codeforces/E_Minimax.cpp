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

string get(int x, int i){
    string s;
    for(int j = 0; j < x; j++)s += (i+'a');
    return s;
}

void solve(){
    string s; cin >> s;
    int n = sz(s);

    if(count(all(s),s[0]) == n){
        cout<<s<<endl;return;
    }

    vector<int> f(26,0);
    string st;

    for(auto c: s){
        f[c-'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(f[i]){
            st += (i+'a');
        }
        if(f[i] == 1){
            string t;
            t += get(1,i);
            f[i]--;
            for(int j = 0; j < sz(f); j++){
                t += get(f[j],j);
            }
           cout<<t<<endl;return;
        }
    }

    for(int j = 0; j < 26; j++){
        if(f[j]){
            int baki = n - f[j];
            if(f[j]-2 <= baki){
                string t;
                t += get(2,j);
                f[j] -= 2;

                for(int i = 0; i < 26; i++){
                    if(i == j)continue;
                    while(f[i] && f[j]){
                        t += get(1,i);
                        t += get(1,j);
                        f[i]--,f[j]--;
                    }
                }
                for(int i = 0; i < 26; i++){
                    t += get(f[i],i);
                }
                cout<<t<<endl;return;
            }
            break;
        }
    }

    string ans = string(n,'z');
    sort(all(st));
   

    if(sz(st) >= 3){
        string t;
        t += st[0];
        t += st[1];
         t += get(f[st[0]-'a']-1,st[0]-'a');
         t += st[2];
         for(int i = 0; i < 26; i++){
            if(i == (st[0]-'a'))continue;
            if(i == (st[0]-'a') || i == (st[1]-'a') || i ==(st[2]-'a'))
            t += get(f[i]-1,i);
            else 
            t += get(f[i],i);
         }
         ans = min(ans,t);
    }
    string t;
    t += st[0];
    t += get(f[st[1]-'a'],st[1]-'a');
    f[st[1]-'a'] = 0;
    f[st[0]-'a']--;
    for(int i = 0; i < 26; i++){
        t += get(f[i],i);
    }

    ans = min(ans,t);
    cout<<ans<<endl;
    
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
