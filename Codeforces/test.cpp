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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}

void gen(){      //input generator
     freopen("input.txt","w",stdout);
     int t = my_rand(10,20);
     cout<<t<<endl;
     while(t--){
            int n = my_rand(15,20);
            cout<<n<<endl;
             for(int i = 0; i < n; i++){
                    cout<<my_rand(0,100)<<" \n"[i==n-1];
         }
     }
}

int sol(vector<int> a){
    int n = sz(a);
    sort(a.begin(),a.begin()+n-1);
    return a[1];
}

int brute(vector<int> a){
       sort(all(a));
       return a[1];
}

bool cmp(int tc){
    //Taking input for a single sample test
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
            cin >> a[i];
    }

    //Comparing bruteforce solution with my solution
    if(sol(a) == brute(a)){
            cout<<tc<<" ok\n";
            return true;
    }else{
        cout<<tc<<"-> Expected : "<<brute(a)<<" Found : "<<sol(a)<<endl;
        cout<<n<<endl;
        print(a);
        return false;
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // gen();

    freopen("input.txt","r",stdin);
    int t = 0;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cmp(tc);
    }

    return 0;
}

