class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(vector<int>& candidates, int target, int index) {

        // Base case
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicate at the same level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted
            if (candidates[i] > target)
                break;

            // TAKE
            current.push_back(candidates[i]);

            // i + 1 -> cannot reuse same element
            backtrack(candidates, target - candidates[i], i + 1);

            // BACKTRACK
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return ans;
    }
};