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

string to_lower(string s){
    for(int i = 0; i < sz(s); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = (s[i]-'A'+'a');
        }
    }
    return s;
}

bool is_char(char c){
    return ((c>='a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void solve(){
    string shortest = "",longest = "", most_freq = "";

    string s;map<string,int>mp;

    while(cin >> s){
        while(!is_char(s.back()))s.pop_back();
        while(!is_char(s[0])) s = s.substr(1);

        string t = to_lower(s);
        mp[t]++;
        //debug(s);
        if(sz(shortest) == 0){
            shortest = s;
            longest = s;
            most_freq = s;
        }else{
            if(mp[t] > mp[to_lower(most_freq)])most_freq = s;
            if(sz(shortest) > sz(s)) shortest = s;
            if(sz(longest) < sz(s))longest = s;
        }
    }

    cout << longest <<endl;
    cout << shortest<<endl;
    cout << most_freq<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

