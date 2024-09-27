ar<int,2> dfs(int u, int p){
    ar<int,2> ret={-1,u};
    if(A[u])ret[0]=0;
    for(auto v: g[u]){
        if(v==p)continue;
        ar<int,2> x=dfs(v,u);
        if(x[0]==-1)continue;
        if(x[0]+1>ret[0])ret[0]=x[0]+1,ret[1]=x[1];
    }
    return ret;
}
