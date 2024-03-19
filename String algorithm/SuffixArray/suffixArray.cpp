//collected
struct suffixArray {
    int n;
    string s;
    vector<int> sa,lcp;
    const int sigma=300;

    void cnt_sort(int k, const vector<int>& rnk) {
        vector<int>cnt(max(sigma,n),0);
        for(int i=0; i<n; i++) {
            cnt[(i+k<n)?rnk[i+k]:0]+=1;
        }
        int sum=0;
        for(int i=0; i<sz(cnt); i++) {
            int ci=cnt[i];
            cnt[i]=sum;
            sum+=ci;
        }

        vector<int>tmp_sa(n);
        for(int i=0; i<n; i++) {
            int pos=(sa[i]+k<n)?rnk[sa[i]+k]:0;
            tmp_sa[cnt[pos]++]=sa[i];
        }
        sa.swap(tmp_sa);
    }

    void construct_sa() {
        sa.resize(n);
        iota(all(sa),0);
        vector<int>rnk(n,0);
        for(int i=0; i<n ; i++)rnk[i]=s[i];
        for(int k=1; k<n; k<<=1) {
            cnt_sort(k,rnk);
            cnt_sort(0,rnk);
            int r=0;
            vector<int>tmp_rnk(n);
            tmp_rnk[sa[0]]=r;
            for(int i=1; i<n; i++) {
                if(rnk[sa[i]]==rnk[sa[i-1]] && rnk[sa[i]+k]==rnk[sa[i-1]+k])
                    tmp_rnk[sa[i]]=r;
                else tmp_rnk[sa[i]]=++r;
            }
            rnk.swap(tmp_rnk);
            if(rnk[sa[n-1]]==n-1)break;
        }
    }

    pair<int,int> find(const string& p) {
        pair<int,int>ret;
        {
            int l=0,h=n-1;
            while(l!=h) {
                int m=(l+h)/2;
                if(s.compare(sa[m],sz(p),p)>=0)h=m;
                else l=m+1;
            }
            if(s.compare(sa[l],sz(p),p)!=0)return {-1,-2};
            ret.first=l;
        }
        {
            int k=0;
            while((1<<k)<n)k+=1;
            int h=ret.first;
            for(int bit=k-1; bit>=0; bit--) {
                if(h+(1<<bit)<n && s.compare(sa[h+(1<<bit)],sz(p),p)==0)h+=(1<<bit);
            }
            ret.second=h;
        }
        return ret;
    }

    void construct_lcp() {
        vector<int>rnk(n,0);
        for(int i=0; i<n; i++)rnk[sa[i]]=i;
        int k=0;
        lcp.resize(n-1,0);
        for(int i=0; i<n; i++) {
            if(rnk[i]==n-1) {
                k=0;
                continue;
            }
            int j=sa[rnk[i]+1];
            while(max(i,j)+k<n && s[i+k]==s[j+k])k++;
            lcp[rnk[i]]=k;
            k=max(0ll,k-1);
        }
    }

    suffixArray(const string& ss) {
        s=ss;
        s+='!';
        n=sz(s);
        construct_sa();
        construct_lcp();
    }


};
