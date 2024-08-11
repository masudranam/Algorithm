#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
//#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> pf(string s){
    int n = s.size();
    vector<int> p(n);

    for(int i = 1; i < n; i++){
        int k = p[i-1];
        while(k > 0 && s[i] != s[k]){
            k = p[k-1];
        }
        k += (s[i] == s[k]);
        p[i] = k;
    }
    return p;
}


void solve(){
    string s; cin >> s;
    int n = s.size();

    vector<int> p = pf(s);
    vector<vector<int>>A(n, vector<int>(26));

    // cout << "   ";
    // for(char c = 'a'; c <= 'z'; c++){
    //     cout << c <<' ';
    // } cout << '\n';
    // Prefix function automation which allow to insert char in O(1)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(i > 0 && j != s[i] - 'a'){
                A[i][j] = A[p[i-1]][j];
            }else{
                A[i][j] = i + (j == s[i] - 'a');
            }
        }
        // cout << i << "->";
        // for(int j = 0; j < 26; j++){
        //     cout << A[i][j] << ' ';
        // }  cout << '\n';
    }

    int q; cin >> q;
    vector<vector<int>>res(q);

    for(int id = 0; id < q; id++){
        string t; cin >> t;
        int m = t.size();
        s += t;
       
        for(int i = n; i < n + m; i++){
            A.push_back(vector<int>(26)); 
            for(int j = 0; j < 26; j++){
                if(j != s[i]-'a'){
                    A[i][j] = A[p[i - 1]][j];
                }else{
                    A[i][j] = i + (j == s[i] - 'a');
                }
            }
            p.push_back(A[p[i - 1]][s[i]-'a']);
            res[id].push_back(p[i]);
        }
        while(m--){
            s.pop_back();
            A.pop_back();
            p.pop_back();
        }
    }

    for(int i = 0; i < q; i++){
        print(res[i]);
    }
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