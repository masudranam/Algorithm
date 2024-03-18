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

bool ok(int x){
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0)return false;
    }
    return true;
}



struct Hash {
    string  s;
    const int p = 397, p1 = 313;
    int len;
    vector<int> pw1, pw, hF1, hF, hR1, hR;

    Hash(string s1) {
        s=s1;
        this->len=sz(s);
        pw = hF = hR = vector<int>(len+5,0);
        pw1 = hF1 = hR1 = vector<int>(len+5,0);
    }

    void Calc() {
        pw[0]=1;
        hF[0] = hR[len+1] = 0;
        for(int i=1; i<=len; i++) {
            pw[i]=(pw[i-1]*p)%M;
        }
        for(int i=0; i<len; i++) {
            hF[i+1] = (hF[i] * p + (s[i]) ) % M;
            hR[len-i] = (hR[len-i+1] * p + (s[len-i-1])) % M;
        }
    }

    int hashF(int l,int r) {
        int val = hF[r] - (hF[l - 1] * pw[r - l + 1]) % M;
        if(val<0)val+=M;
        return val;
    }

    int hashR(int l,int r) {
        int val = hR[l] - (hR[r + 1] * pw[r - l + 1]) % M;
        if(val<0)val+=M;
        return val;
    }

    bool isPalin(int l,int r) {
        if(r<l)return false;
        return (hashF(l, r) == hashR(l, r));
    }


    void Calc1() {
        pw1[0] = 1;
        hF1[0] = hR1[len + 1] = 0;
        pw[0] = 1;
        hF[0] = hR[len + 1] = 0;

        for (int i = 1; i <= len; i++) {
            pw1[i] = (pw1[i - 1] * p1) % M;
            pw[i] = (pw[i - 1] * p) % M;
        }
        for (int i = 0; i < len; i++) {
            hF1[i + 1] = (hF1[i] * p1 + (s[i])) % M;
            hF[i + 1] = (hF[i] * p + s[i]) % M;
            hR1[len - i] = (hR1[len - i + 1] * p1 + (s[len - i - 1])) % M;
            hR[len - i] = (hR[len - i + 1] * p + (s[len - i - 1])) % M;
        }
    }

    ar<int, 2> hashF1 (int l, int r) {
        int val1 = hF1[r] - (hF1[l - 1] * pw1[r - l + 1]) % M;
        int val2 = hF[r] - (hF[l - 1] * pw[r - l + 1]) % M;
        if (val1 < 0) val1 += M;
        if (val2 < 0) val2 += M;
        return {val1, val2};
    }

    ar<int, 2> hashR1 (int l, int r) {
        int val1 = hR1[l] - (hR1[r + 1] * pw1[r - l + 1]) % M;
        int val2 = hR[l] - (hR[r + 1] * pw[r - l + 1]) % M;
        if (val1 < 0) val1 += M;
        if (val2 < 0) val2 += M;
        return {val1, val2};
    }

    bool isPalin1(int l,int r) {
        if(r<l)return false;
        return (hashF1(l, r) == hashR1(l, r));
    }
};

void solve(){
    string s; cin >> s;
    int n = sz(s);

    vector<int> pr;
   for(int i = 1; i <= n; i++){
    if(ok(i))pr.push_back(i);
   }

    Hash h(s);
    h.Calc1();

    int ans = 0;
    vector<vector<ar<int,2>>>c(n+1,vector<ar<int,2>>(n+1));

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            c[i][j] = h.hashF1(i+1,j+1);
        }
    }

    for(int i = 0; i < n; i++){
        for(int k = 0; k < sz(pr); k++){
            int j = i+2*pr[k]-1;
            bool ok = 1;
            while(j < n && ok){
                int l = j-pr[k]+1;
                ok &= (c[i][i+pr[k]-1] == c[l][j]);
                if(ok)ans = max(ans,j-i+1);
                j += pr[k];
            }
        }
    }


    if(ans == 1)ans = 0;
    cout<<ans<<endl;
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

