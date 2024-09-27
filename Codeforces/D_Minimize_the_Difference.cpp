#include<bits/stdc++.h>
using namespace std;
#define int   long long int
 
const int M = 3e13 + 7;
const int N = 3e5 + 10;

int a[N], b[N];
int n;

bool f(int val){
    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }


    
int sum = 0;
    for(int i = 0; i < n; i++){
        if(b[i] + sum < val)return false;
        if(b[i] >= val)sum += (b[i] - val);
        else{
            sum -= (val - b[i]);
            b[i] = val;
        }
    }
return true;
}

bool ff(int val){
for(int i = 0; i < n; i++){
    b[i] = a[i];
}

int sum = 0;
    for(int i = 0; i < n; i++){
        if(b[i] >= val)sum += (b[i] - val);
        else{
            sum -= min(sum,val - b[i]);
        }
    }
return sum == 0;
}


signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

    int t; cin >> t;
    while(t--){
           cin >> n;
for(int i = 0; i < n; i++){
    cin >> a[i];
}
    if(n == 1){
        cout << 0 << '\n';
        continue;
    }

    int res = M;
    int l = 0, r = a[0];
    
while(r - l > 0){
    int m = (l + r + 1) / 2;
    if(f(m)){
        int l1 = m, r1 = M;
        while(r1 - l1 > 0){
            int m1 = (r1 + l1) / 2;
            if(ff(m1))r1 = m1;
            else l1 = m1 + 1;
        }
        res = min(res, abs(m - l1));
        l = m;
    }else{
        r = m - 1;
    }
}
    cout << res << '\n';
}
   return 0;
}
