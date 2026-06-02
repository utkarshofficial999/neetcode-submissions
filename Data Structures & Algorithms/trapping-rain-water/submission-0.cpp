class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        
        int left_max = 0;
        int right_max = 0;
        int total_water = 0;
        while (left < right) {
            // Process the left side if it's the smaller boundary
            if (height[left] <= height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left]; // Found a new wall, no water can be trapped here
                } else {
                    total_water += left_max - height[left]; // Trap water!
                }
                left++; // Move inward
            } 
            // Process the right side if it's the smaller boundary
            else {
                if (height[right] >= right_max) {
                    right_max = height[right]; // Found a new wall, no water can be trapped here
                } else {
                    total_water += right_max - height[right]; // Trap water!
                }
                right--; // Move inward
            }
        }
        
        return total_water;

    }
};
