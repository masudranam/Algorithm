#include<bits/stdc++.h>
using namespace std;

string t;
bool f;

int give(){
    if(f){
        cout <<"? " << "0" + t <<endl;
        cout.flush();
        int val; cin >> val;
        if(val == 1){
            t = "0" + t;return 1;
        }
        t = "1" + t;return 1;  
    }
    cout <<"? " << t + "0" <<endl;
    cout.flush();
    int val; cin >> val;
    if(val == 1){
        t += '0';return 1;
    }

    cout << "? " << t + "1" <<endl;
    cout.flush();
    cin >> val;

    if(val == 1){
        t += '1';return 1;
    }
    f = 1;
    return 1;
}

void solve(){
    int n; cin >> n;
    t = ""; f = 0;
    while((int)t.size() < n){
        give();
    }
    cout << "! " << t << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;
   cin >> t;
   while(t--)solve();
   return 0;
}
