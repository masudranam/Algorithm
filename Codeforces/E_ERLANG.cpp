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

string s;
int n;



void solve(){
    cin >> n;
    cin >> s;
    Hash h(s);
    h.Calc1();

    auto ok = [&](int x){
        for(int i = x; i+x <= n; i++){
            for(int j = i+x; j <= n; j++){
                if(h.hashF1(i-x+1,i) == h.hashF1(j-x+1,j))return true;
            }
        }
        return false;
    };

    int l = 0, r = (n/2)+1;
    while(r-l>0){
        int m = (l+r+1)/2;
        if(ok(m))l = m;
        else r = m-1;
    }
    cout<<l<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

