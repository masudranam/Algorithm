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

struct ST{
    int n;
    const int LOG = 22;
    vector<int> a,pw;
    vector<vector<int>>mx,mn;

    ST(vector<int> _a){
        a = _a; n = (int)a.size();  pw = vector<int>(n+10);
        mx = mn = vector<vector<int>>(n+1,vector<int>(LOG+1));

        pw[1] = 0;
        for(int i = 2; i <= n; i++){
            pw[i] = pw[i/2] + 1;
        }
        for(int i = 0; i < n; i++){
            mx[i][0] = mn[i][0] = a[i];
        }

        for(int k = 1; k < LOG; k++){
            for(int i = 0; (i+(1<<k)-1) < n; i++){
                mx[i][k] = max(mx[i][k-1],mx[i+(1<<(k-1))][k-1]);
                mn[i][k] = min(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
            }
        }
    }
    
        int qmx(int l, int r){
            int k = pw[r-l+1];
            return max(mx[l][k],mx[r-(1<<k)+1][k]);            
        }
        int qmn(int l, int r){
            int k = pw[r-l+1];
            return min(mn[l][k],mn[r-(1<<k)+1][k]);
        }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ST st(a);

    vector<int> s(n);
    for(int i = 0; i < n; i++){
        s[i] = a[i];
        if(i)s[i] += s[i-1];
    }

    vector<int> ans(n,n);

    for(int i = 0; i < n; i++){
        if((i && a[i-1] > a[i]) || (i+1 < n && a[i+1] > a[i])){
            ans[i] = 1;continue;
        }

        int l = 0, r = i-1, sum = 0;
        int cur = n;
        while(r-l > 0){
            int m = (l+r+1)/2;
            sum = s[i-1] - (m?s[m-1]:0);
            if(st.qmx(m,i-1) != st.qmn(m,i-1) && sum > a[i]){
                l = m;
            }else{
                r = m-1;
            }
        }

        sum = (i?s[i-1]: 0) - (l?s[l-1]:0);
        if(i && sum > a[i] && (st.qmx(l,i-1) != st.qmn(l,i-1))){
            ans[i] = i - l;
        }


        l = i+1, r = n-1;
        while(r-l > 0){
            int m = (l+r)/2;
            sum = s[m] - s[i];
            if(st.qmx(i+1,m) != st.qmn(i+1,m) && sum > a[i]){
                r = m;
            }else{
                l = m+1;
            }
        }

        sum = s[r] - s[i];
        if(r > i && sum > a[i] && (st.qmx(i+1,r) != st.qmn(i+1,r))){
            ans[i] = min(ans[i], r - i);
        }
    }

    for(int i = 0; i < n; i++){
        if(ans[i] == n)ans[i] = -1;
        cout << ans[i] <<' ';
    }
    cout << endl;
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

