class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int current_sum=0;
        int count = 0;
        unordered_map<int,int>prefix_map;
        prefix_map[0]=1;
       for(int num:nums){
       current_sum += num;  
       if(prefix_map.find(current_sum-k)!=prefix_map.end()){
        count+=prefix_map[current_sum-k];
       } 
       prefix_map[current_sum]++;
           }
           return count;
    }
};