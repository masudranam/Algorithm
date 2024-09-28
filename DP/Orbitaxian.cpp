#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define int long long int

const int MOD = 1000000007;
const std::string P = "orbitaxian";
const int L = P.size();

int countSubsequences(const std::string& S, int K) {
    int N = S.size();
    
    // Initialize DP table
    std::vector<std::vector<int>> dp(L + 1, std::vector<int>(N + 1, 0));
    
    // Base case: There's exactly one way to form the empty subsequence
    for (int j = 0; j < N; ++j) {
        if(s[j] == P[0])
        dp[0][j] = 1;
    }
    dp[0][0] = 1;


    for (int i = 1; i <= L; ++i) {
        std::vector<int> cumulativeSum(N + 1, 0);
        
        cumulativeSum[0] = dp[i - 1][0];
        for (int j = 1; j <= N; ++j) {
            cumulativeSum[j] = (cumulativeSum[j - 1] + dp[i - 1][j]) % MOD;
        }
        
        for (int j = 1; j <= N; ++j) {
            if (S[j - 1] == P[i - 1]) {
                int start = std::max(0ll, j - K);
                dp[i][j] = (cumulativeSum[j - 1] - (start > 0 ? cumulativeSum[start - 1] : 0) + MOD) % MOD;
            }
        }
    }

   
    int result = 0;
    for (int j = 1; j <= N; ++j) {
        result = (result + dp[L][j]) % MOD;
    }
    
    return result;
}

signed main() {
    int T;
    std::cin >> T;
    
    while (T--) {
        int N, K;
        std::cin >> N >> K;
        std::string S;
        std::cin >> S;
        std::cout << countSubsequences(S, K) << std::endl;
    }
    
    return 0;
}
