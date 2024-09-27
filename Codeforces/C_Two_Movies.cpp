#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int a[N], b[N];
int n;


void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    
    int as = 0, bs = 0, cnt = 0, bonus = 0;
    set<int> st;
    for(int i  = 0; i < n; i++){
        if(a[i] == 1 && (b[i] == -1 || b[i] == 0)){
            as += 1;
        }else if(b[i] == 1 && (a[i] == -1 || a[i] == 0)){
            bs += 1;
        }else if(a[i] == -1 && b[i] == -1){
            cnt++;
        }else if(a[i] == 1 && b[i] == 1)bonus++;
    }

    while(cnt > 0){
        if(as > bs)as--,cnt--;
        else bs--,cnt--;
    }
    while(bonus>0){
        if(as > bs)bs++,bonus--;
        else as++,bonus--;
    }
    cout << min(as,bs) << '\n';


  
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

