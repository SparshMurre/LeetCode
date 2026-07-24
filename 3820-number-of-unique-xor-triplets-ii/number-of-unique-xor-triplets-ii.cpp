class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        unordered_set<int> pairXor;
        bitset<2048> seen;   // nums[i] <= 1500, so XOR < 2048

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        for (int x : pairXor) {
            for (int v : nums) {
                seen.set(x ^ v);
            }
        }

        return seen.count();
    }
};