class Solution {
public:
    int maxArea(vector<int>& heights) {
    int left = 0;
    int right = heights.size() - 1;
     int max_water = 0;
     while(left<right){
        int current_area = min(heights[left], heights[right]) * (right - left);
        max_water=max(max_water,current_area);
        if(heights[left]<heights[right]){
            left++;
        }
        else{
            right--;
        }
        }
        return max_water;
     }
    
};
