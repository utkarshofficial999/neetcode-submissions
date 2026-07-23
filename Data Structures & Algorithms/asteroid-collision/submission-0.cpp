class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for (int a : asteroids) {
            while (!stack.empty() && a < 0 && stack.back() > 0) {
                int diff = a + stack.back();

                if (diff < 0) {
                    stack.pop_back(); // Current asteroid destroyed top asteroid; keep checking
                } else if (diff > 0) {
                    a = 0; // Current asteroid destroyed by top asteroid
                } else {
                    a = 0;
                    stack.pop_back(); // Both asteroids destroyed
                }
            }

            // Push if the asteroid survived
            if (a != 0) {
                stack.push_back(a);
            }
        }

        return stack;
    }
};