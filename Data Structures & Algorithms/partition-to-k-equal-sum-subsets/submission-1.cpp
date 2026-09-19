class Solution {
public:

    bool backtrack(vector<int>& nums, vector<int>& buckets,
                   int index, int target) {

        // All numbers placed
        if (index == nums.size()) {
            return true;
        }

        int num = nums[index];

        for (int i = 0; i < buckets.size(); i++) {

            // Skip duplicate bucket states
            if (i > 0 && buckets[i] == buckets[i - 1])
                continue;

            // Number doesn't fit
            if (buckets[i] + num > target)
                continue;

            // Put number
            buckets[i] += num;

            // Try next number
            if (backtrack(nums, buckets, index + 1, target))
                return true;

            // Undo
            buckets[i] -= num;

            // If this was an empty bucket,
            // don't try other empty buckets
            if (buckets[i] == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        // Cannot divide equally
        if (sum % k != 0)
            return false;

        int target = sum / k;

        // Biggest number cannot fit
        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        vector<int> buckets(k, 0);

        return backtrack(nums, buckets, 0, target);
    }
};