class Solution {
public:
    bool backtrack(vector<int>& sticks, vector<int>& sides, int index, int target) {
        
       
        if (index == sticks.size())
            return true;

        int stick = sticks[index];

       
        for (int i = 0; i < 4; i++) {

            if (sides[i] + stick > target)
                continue;

            
            sides[i] += stick;

            
            if (backtrack(sticks, sides, index + 1, target))
                return true;

            
            sides[i] -= stick;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        
        int sum = 0;

        for (int x : matchsticks)
            sum += x;

        \
        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        vector<int> sides(4, 0);

        return backtrack(matchsticks, sides, 0, target);
    }
};