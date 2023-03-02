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

int n, k, x, a[N];

struct node {
   int sum, pfs, sufs, subs;

} st[4 * N];

node Merge (node l, node r) {
   node p;
   p.sum = l.sum + r.sum;
   p.pfs = max (l.pfs, l.sum + r.pfs);
   p.sufs = max (r.sufs, r.sum + l.sufs);
   p.subs = max ({l.subs, r.subs, l.sufs + r.pfs});
   return p;
}

void upd (int l1, int x, int i = 1, int l2 = 0, int r2 = n - 1) {
   if (l2 == r2) {
      st[i].sum = x;
      st[i].pfs = x;
      st[i].sufs = x;
      st[i].subs = x;
      return;
   }
   int mid = (l2 + r2) / 2;
    if(l1<=mid)upd (l1, x, 2 * i, l2, mid);
	 else upd(l1, x, 2 * i + 1, mid + 1, r2);
   st[i] = Merge (st[2 * i], st[2 * i + 1]);
}



void solve() {
   cin >> n >> k >> x;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
      if(i<k)
      upd (i, a[i]+x);
      else upd(i,a[i]-x);
   }
   int ans = st[1].subs;
	ans=max(ans,0ll);
	if(k==0){
		cout<<ans;return;
	}                    
   for (int i = k, j = 0; i < n + k; i++) {
      upd (i - k, a[i - k] - x);
      upd (i % n, a[i % n] + x);
      ans = max (ans, st[1].subs);
   }

   cout << ans;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout << "Case " << tc << ": \n";
      solve();
      if (tc < t) cout << '\n';
   }
   return 0;
}
