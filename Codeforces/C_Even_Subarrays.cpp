#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int ar[n];
    for(int i = 0; i < n; i++) cin >> ar[i];
    int cnt = 0, cur = 0;
    int mp[n + 10] = {0};
    mp[0] = 1;
    for(int i = 0; i < n; i++){
        cur ^= ar[i];
        for(int j = 0; j * j <= n; j++){
            cnt += mp[cur^(j*j)];
        }
        mp[cur]++;
        //cout << i << " " << cnt << '\n';
    }

    cout << (1LL * n * (n + 1)) / 2LL - cnt << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}