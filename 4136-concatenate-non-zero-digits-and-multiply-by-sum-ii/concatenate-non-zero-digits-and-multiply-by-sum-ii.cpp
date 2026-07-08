class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;

        auto solendivar = make_pair(s, queries);

        int n = s.size();

        vector<int> left(n), right(n), id(n, -1);
        vector<int> prefSum(1, 0);
        vector<long long> prefNum(1, 0);
        vector<long long> pow10(1, 1);

        int cnt = 0;

        // left[i] = number of non-zero digits before i
        for (int i = 0; i < n; i++) {
            left[i] = cnt;
            if (s[i] != '0') {
                id[i] = cnt;
                cnt++;
                int d = s[i] - '0';
                prefSum.push_back(prefSum.back() + d);
                prefNum.push_back((prefNum.back() * 10 + d) % MOD);
                pow10.push_back((pow10.back() * 10) % MOD);
            }
        }

        // right[i] = index in compressed array of first non-zero >= i
        int cur = cnt;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') cur--;
            right[i] = cur;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = right[q[0]];
            int r = (q[1] == n - 1) ? cnt : left[q[1] + 1];

            if (l >= r) {
                ans.push_back(0);
                continue;
            }

            long long x =
                (prefNum[r] - prefNum[l] * pow10[r - l] % MOD + MOD) % MOD;

            long long sum = prefSum[r] - prefSum[l];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};