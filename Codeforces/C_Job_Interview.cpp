#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;


void solve1(){
    int n, m;
    cin >> n >> m;
    vector<array<int,4>> c(n+m+1);
    vector<int> x(n+m+1), y(n+m+1);
    for(int i = 0; i < n + m + 1; i++){
        cin >> x[i];
    }
    for(int i = 0; i < n + m + 1 ; i++){
        cin >> y[i];
    }

    for(int i = 0; i < n + m + 1 ; i++){
         c[i] = {x[i] < y[i], i, x[i], y[i]};
    }

    sort(c.begin(),c.end());

    vector<array<int,4>> d, e;

    for(int i = 0; i < n + m + 1; i ++){
        if(d.size() <= n && c[i][0] == 0){
            d.push_back(c[i]);
        }else if(e.size() < m)e.push_back(c[i]);
        else d.push_back(c[i]);
    }

    for(auto it : e)d.push_back(it);
    vector<int> a(n+m+4),b(n+m+5);

    for(int i = 0; i < n + m + 1; i++){
        cout << d[i][0] << ' '<<d[i][1]<<' ' <<d[i][2] << ' '<<d[i][3] <<  '\n';
    }

    for(int i = 0; i < n + m + 1; i++){
        a[i+1] = d[i][2] + a[i];
        b[i+1] = d[i][3] + b[i];
    }

    print(a);
    print(b);

    vector<int> res(n+m+1);

    for(int i = 0; i < n + m + 1 ; i++){
        int cur = 0;
        if(i <= n){
            cur += a[n+1];
            cur += (b[n+m+1] - b[n+1]);
            cur -= d[i][2];
        }else{
            cur += a[n];
            cur += (b[n+m+1] - b[n]);
            cur -= d[i][3];
        }
        res[d[i][1]] = cur;
    }   
    
for(int i = 0; i < n + m + 1; i++){
    cout << res[i] << ' ';
}
cout << '\n';
}

void solve(){
    int n, m;
    cin >> n >> m;
    int len = n + m + 1;
    vector<int> a(len+1),b(len+1), sa(len+3),sb(len+3),ps(len+2),ca(len+1),cb(len+1);

   for(int i = 1; i <= len; i++){
    cin >> a[i];
   } 

   for(int i = 1; i <= len; i++){
    cin >> b[i];
    if(a[i] > b[i])ca[i]++;
    else cb[i]++;

    ps[i] = ps[i-1] + max(a[i], b[i]);
    ca[i] += ca[i-1];
    cb[i] += cb[i-1];
   }

   for(int i = len; i >= 1; i--){
    sa[i] = sa[i+1] + a[i];
    sb[i] = sb[i+1] + b[i];
   }

   vector<int> ans(len+1);


   for(int i = 1; i <= len; i++){
        if(n == 0){
            ans[i] = sb[1] - b[i];
            continue;
        }
        if(m == 0){
            ans[i] = sa[1] - a[i];
            continue;
        }

        int l = 1, r = len;
        while(r - l > 0){
            int mid = (l + r) / 2;
            if(ca[mid] >= n || cb[mid] >= m){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        int cur = 0;
        if(ca[l] == n){
            if(i > l+1){
                cur = ps[l] + sb[l+1] - b[i];
            }else{
                cout << l << ' ';
                l = lower_bound(ca.begin(),ca.end(),n+1) - ca.begin();
                cout << l << '\n';
                cur = ps[l] + sb[l+1] - max(a[i],b[i]);
            }
        }else{
            if(i > l+1){
                cur = ps[l] + sa[l+1] - a[i];
            }else{
                cout << l << ' ';
                l = lower_bound(cb.begin(),cb.end(),m+1) - cb.begin();
                cout << l << '\n';
                cur = ps[l] + sa[l+1] - max(a[i],b[i]);
            }
        }
        ans[i] = cur;
   }

   for(int i = 1; i <= len; i++) cout << ans[i] << ' ';cout << '\n';

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

