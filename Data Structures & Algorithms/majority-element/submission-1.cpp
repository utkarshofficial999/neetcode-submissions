class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>countMap;
        int n=nums.size();
        for(int num:nums){
            countMap[num]++;
            if(countMap[num]>n/2){
                return num;
            }
        }
        return -1;
    }
};