class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[201][201];
    int ndp[201][201];

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int x : nums) {
            memcpy(ndp, dp, sizeof(dp));

            for (int g1 = 0; g1 <= 200; g1++) {
                for (int g2 = 0; g2 <= 200; g2++) {
                    if (!dp[g1][g2]) continue;

                    int ng1 = (g1 == 0 ? x : gcd(g1, x));
                    int ng2 = (g2 == 0 ? x : gcd(g2, x));

                    ndp[ng1][g2] = (ndp[ng1][g2] + dp[g1][g2]) % MOD;
                    ndp[g1][ng2] = (ndp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }

            memcpy(dp, ndp, sizeof(dp));
        }

        long long ans = 0;
        for (int g = 1; g <= 200; g++)
            ans = (ans + dp[g][g]) % MOD;

        return ans;
    }
};