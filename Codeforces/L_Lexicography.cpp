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


void del(string &s, string &t,int k){
    t += s.substr(sz(s)-k);

    while(sz(s) && k--){
        s.pop_back();
    }
}

void solve(){
    int n, l, k;
    cin >> n >> l >> k;

    string s; cin >> s;
    sort(all(s));

    vector<string> a(n);

    for(int i = 0; i < n; i++){
        a[i] = string(l,'0');
    }


    string t = s.substr(0,k*l);
    string extra;
    int b = 0,id = 0;

    for(int j = 0; j < l; j++){
        for(int i = b; i < k; i++){
            a[i][j] = t[id++];
            if(i && a[i-1][j] != '0' && a[i-1][j] < a[i][j]){
                int x = (i-b)*(l-j-1);
                del(t,extra,x);
                b = i;
            }
        }
    }
    extra += s.substr(k*l);
    id = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < l; j++){
            if(a[i][j] != '0')continue;
            a[i][j] = extra[id++];
        }
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

