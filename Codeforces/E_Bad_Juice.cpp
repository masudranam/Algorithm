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
    cout.flush();
    int m = n/3;
    int ans = 0;
    if(n%3 == 1){
        cout << 2*m+1 << endl;
        cout.flush();
        cout << 1 <<' '<<n<<endl;
        cout.flush();
        for(int i = 0; i < m; i++){
            cout << 2 <<' '<<3*i+1<<' '<<3*i+2<<endl;
            cout.flush();
            cout << 1 << ' '<<3*i+3<<endl;
        }
      cout.flush();
        string s; cin >> s;
        if(s[0] == '1')ans++;
        for(int i = 2; i < 2*m+1; i++){
            if(s[i] == '1' && s[i-1] == '1')ans+=2;
            else if(s[i] == '1')ans++;
        }
        cout << ans << endl;
    }else if(n%3 == 2){
         cout << 2*m+2 << endl;
         cout.flush();
        cout << 1 <<' '<<n<<endl;
        cout << 1 <<' '<<n-1 << endl;
        cout.flush();

        for(int i = 0; i < m; i++){
            cout << 2 <<' '<<3*i+1<<' '<<3*i+2<<endl;
            cout.flush();
            cout << 1 << ' '<<3*i+3<<endl;
            cout.flush();
        }
        cout.flush();
        string s; cin >> s;
        if(s[0] == '1')ans++;
        if(s[1] == '1')ans++;

        for(int i = 3; i < 2*m+2; i++){
            if(s[i] == '1' && s[i-1] == '1')ans+=2;
            else if(s[i] == '1')ans++;
        }
        cout << ans << endl;
    }else{
        cout.flush();
         cout << 2*m << endl;

        for(int i = 0; i < m; i++){
            cout << 2 <<' '<<3*i+1<<' '<<3*i+2<<endl;
            cout.flush();
            cout << 1 << ' '<<3*i+3<<endl;
            cout.flush();
        }
        string s; cin >> s;
       
        for(int i = 1; i < 2*m; i++){
            if(s[i] == '1' && s[i-1] == '1')ans+=2;
            else if(s[i] == '1')ans++;
        }
        cout << ans << endl;
        cout.flush();
    }

    cout.flush();
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

