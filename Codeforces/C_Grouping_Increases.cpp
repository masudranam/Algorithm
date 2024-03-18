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
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
	vector<int> b{0},c{0};
int ans = 0;
	for(int i = n-1; i >= 0; i--){
		if(b.back() <= a[i] && c.back() <= a[i]){
			if(abs(a[i]-b.back()) < abs(a[i]-c.back()))b.push_back(a[i]);
			else c.push_back(a[i]);
		}
		else if(b.back() <= a[i])b.push_back(a[i]);
		else if(c.back() <= a[i])c.push_back(a[i]);
		else{
			ans++;
			if(b.back() > c.back())b.push_back(a[i]);
			else c.push_back(a[i]);
		}
	}
	cout << ans << endl;
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

