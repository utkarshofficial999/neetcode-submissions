class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; // pair: {temperature, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            
            // Resolve all previous days that are cooler than today
            while (!stack.empty() && t > stack.top().first) {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            
            // Push current day onto the stack
            stack.push({t, i});
        }

        return res;
    }
};