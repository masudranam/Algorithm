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
 
string solve()
{
	string n;
	int k;
	cin >> n >> k;

	while (true)
	{
		set<char> s;
		for (auto c : n) s.insert(c);
   
		if (s.size() <= k) return n;

		s.clear();
		int ptr = 0;
		for (; ; ptr++)
		{
			s.insert(n[ptr]);
			if (s.size() > k)
			{
				while (n[ptr] == '9')ptr--;
					
				n[ptr]++;
				for (int i = ptr + 1; i < n.size(); i++)
					n[i] = '0';
				break;
			}
		}
	}
}
 
signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
 
   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      cout<<solve()<<endl;
   }
   return 0;
}