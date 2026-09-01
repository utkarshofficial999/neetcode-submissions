class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(vector<int>& candidates, int target, int index) {

    
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (index == candidates.size()) {
            return;
        }

        
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            
            backtrack(candidates, target - candidates[index], index);

            
            current.pop_back();
        }

        
        backtrack(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return ans;
    }
};