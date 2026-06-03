class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int current_num=nums[i];
            if(mp.find(current_num)!=mp.end()){
           if(i-mp[current_num]<=k){
            return k;
           }
            }
            mp[current_num]=i;
        }
        return false;
    }
};