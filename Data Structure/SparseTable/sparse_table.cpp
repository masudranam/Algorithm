//collected
int tb[N][20][2]
void build(){
  for(int i = 0; i < n; i++)
    tb[i][0][0] = tb[i][0][1] = a[i];
  for(int j = 1; j <= k; j++)
    for(int i = 0; i <= n - (1 << (j)); i++)
      tb[i][j][0] = max(tb[i][j - 1][0], tb[i + (1 << (j - 1))][j - 1][0]),
        tb[i][j][1] = min(tb[i][j - 1][1], tb[i + (1 << (j - 1))][j - 1][1]);
}
int qry(int l, int r){
  int ans1 = INT_MIN, ans2 = INT_MAX;
  for(int j = k; j >= 0; j--)
    if(l + (1 << j) - 1 <= r)
      ans1 = max(ans1, tb[l][j][0]),
        ans2 = min(ans2, tb[l][j][1]),
          l += (1 << j);
  return ans1 - ans2;
}
