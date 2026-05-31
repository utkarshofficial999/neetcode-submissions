class Solution {
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return; // Base case: 1 or 0 elements

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);      // Sort left half
        mergeSort(nums, mid + 1, right);  // Sort right half

        // Short & Easy Merge Logic
        vector<int> temp;
        int i = left, j = mid + 1;

        // Compare and push the smaller element
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        // Push any leftover elements
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        // Copy the sorted temp array back into the original array
        for (int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};