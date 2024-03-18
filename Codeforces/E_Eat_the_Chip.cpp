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
    int h, w, xa, ya, xb, yb;

    cin >> h >> w;
    cin >> xa >> ya >> xb >> yb;

   int dx = abs(xa - xb), dy = abs(ya - yb);

   if(dx%2 == 1){
    if(ya >= yb){
        while(xa < xb){
            if(abs(xa - xb) == 1){
                if(abs(ya - yb) <= 1)cout<<"Alice\n";
                else cout<<"Draw\n";
                return;
            }
            xa++, xb--;
            ya = max(ya-1,1ll);
            yb = max(yb-1,1ll);
        }
    }else{
         while(xa < xb){
            if(abs(xa - xb) == 1){
                if(abs(ya - yb) <= 1)cout<<"Alice\n";
                else cout<<"Draw\n";
                return;
            }
            xa++, xb--;
            ya = min(ya+1,w);
            yb = min(yb+1,w);
        }
    }
   }else{
     if(ya <= yb){
        while(xa < xb){
            ya = max(ya-1,1ll);
            xa++;
            if(abs(xa - xb) == 1){
                if(abs(ya - yb) <= 1)cout<<"Bob\n";
                else cout<<"Draw\n";
                return;
            }
            xb--;
            yb = max(yb-1,1ll);
        }
    }else{
       while(xa < xb){
            ya = min(ya+1,w);
            xa++;
            if(abs(xa - xb) == 1){
                if(abs(ya - yb) <= 1)cout<<"Bob\n";
                else cout<<"Draw\n";
                return;
            }
            xb--;
            yb = min(yb+1,w);
        }
    }
   }

   cout <<"Draw\n";


    // cin >> h >> w >> xa >> ya >> xb >> yb;
    // swap(xa,ya); swap(xb,yb);

    // if(ya >= yb){
    //     cout<<"Draw\n";
    //     return;
    // }

    // if(abs(xa - xb) > abs(ya - yb)){
    //     cout <<"Draw\n";return;
    // }
    // int dy = abs(ya - yb), dx = abs(xa - xb);

    // // if(abs(xa-xb) <= 1){
    // //     if(dy % 2 == 0){
    // //         cout <<"Bob\n";
    // //     }else cout <<"Alice\n";
    // //     return;
    // // }

    // if(xa == xb){
    //     if(dy%2 == 0)cout<<"Bob\n";
    //     else cout <<"Alice\n";
    //     return;
    // }


    // if(dy%2 == 1){
    //     int dist;
    //     if(xb > xa)dist = w-xb;
    //     else dist = xb-1;
    //         if(dy/2 >= dist && dx >= 2){
    //             cout <<"Draw\n";
    //         }else{
    //             cout<<"Alice\n";
    //         }
    // }else{
    //     int dist;
    //     if(xa > xb)dist = w - xa;
    //     else dist = xa-1;

    //     if(dy/2 <= dist && dx >= 2){
    //         cout<<"Draw\n";
    //     }else{
    //         cout <<"Bob\n";
    //     }
    // }
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

