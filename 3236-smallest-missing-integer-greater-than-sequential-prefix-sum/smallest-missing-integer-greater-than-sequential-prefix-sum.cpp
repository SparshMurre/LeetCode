class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        unordered_set<int> seen;
        seen.reserve(nums.size() * 2);

        for (int x : nums)
            seen.insert(x);

        while (seen.count(sum))
            sum++;

        return sum;
    }
};