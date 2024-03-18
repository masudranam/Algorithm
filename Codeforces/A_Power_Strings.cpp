#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
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
const int p = 397;

struct Hash {
    string  s;
    
    int len;
    vector<int>pw,hF, hR;

    Hash(string s1) {
        s=s1;
        this->len=sz(s);
        pw = hF = hR = vector<int>(len+5,0);
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


   
};

void solve(){
    string s;

    while(true){

        cin >> s;
        if(s == "."){
            break;
        }

    int n = sz(s);
    vector<int> d;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            d.push_back(i);
            if(n/i != i)d.push_back(n/i);
        }
    }
    sort(d.begin(),d.end());

    Hash h(s);

    h.Calc();


    for(int j = 0; j < sz(d); j++){
        int x = d[j];
        bool ok = true;
        for(int i = x; i <= n; i += x){
            ok &= (h.hashF(1,x) == h.hashF(i-x+1,i));
        }

        if(ok){
            cout<<n/x<<endl;
            break;
        }
    }
}


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

