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
const int N = 1e6 + 100;

struct node {
   int lazy;
   int val;
   node* l, *r;
   node() {val = lazy = 0; l = r = NULL;}
};

void lazy (node*& root, int l, int r) {
   if (root->lazy != 0) {
      root->val = root->lazy * (r - l + 1);
      if (l < r) {
         if (root->l == NULL) root->l = new node();
         if (root->r == NULL) root->r = new node();
         root->l->lazy += root->lazy;
         root->r->lazy += root->lazy;
      }
      root->lazy = 0;
   }
}

void upd (node*& root, int l, int r, int b, int e, int x) {
   if (root == NULL) root = new node();
   else lazy (root, l, r);
   if (l > e || r < b) return ;
   if (l >= b && r <= e) {
      root->val += x * (r - l + 1);
      if (l < r) {
         if (root->l == NULL) root->l = new node();
         if (root->r == NULL) root->r = new node();
         root->l->lazy += x;
         root->r->lazy += x;
      }
      return;
   }
   int m = (l + r) >> 1;
   upd (root->l, l, m, b, e, x);
   upd (root->r, m + 1, r, b, e, x);
   root->val = root->l->val + root->r->val;
}

int get (node* root, int l, int r, int b, int e) {
   if (root == NULL) return 0;
   lazy (root, l, r);
   if (l > e || r < b) return 0;
   if (l >= b && r <= e) return root->val;
   int m = (l + r) >> 1;
   return get (root->l, l, m, b, e) + get (root->r, m + 1, r, b, e);
}

void rmv(node *&root){
	if(root==NULL)return;
	rmv(root->l);
	rmv(root->r);
	delete root;
}

void solve() {
   int n, q; cin >> n >> q;
   node* root = NULL;
   while (q--) {
      int i; cin >> i;
      if (i == 0) {
         int l, r, x;
         cin >> l >> r >> x;
         upd (root, 1, n, l, r, x);
      } else {
         int l, r; cin >> l >> r;
         cout << get (root, 1, n, l, r) << endl;
      }
   }
   rmv(root);
}




signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      // cout << "Case " << tc << ": ";
      solve();
   }
   return 0;
}

