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

int n, m;
string s, t;
int pi[N];

void Proces(){
    n = sz(s), m = sz(t);
    pi[0] = -1;
    for(int i = 0, j =-1; i < m;i){
        while(j >= 0 && t[i] != t[j]){
            j = pi[j];
        }
        j++;
        i++;
        pi[i] = j;
    }
}

void Search(){
    for(int i = 0, j = 0; i < n;){
        while(j >= 0 && s[i] != t[j]){
            j = pi[j];
        }
        i++,j++;
        if(j == m){
            cout <<"y\n";
            return;
        }
    }
    cout <<"n\n";
}

void solve(){
    cin >> s;
    int q; cin >> q;
    while(q--){
        cin >> t;
        Proces();
        Search();
    }
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

