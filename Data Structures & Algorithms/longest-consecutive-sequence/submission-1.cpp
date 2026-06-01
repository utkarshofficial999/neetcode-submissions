class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        int longest_streak=0;
        for(int num:s){
        if(s.find(num-1)==s.end()){
        int  current_num=num;
        int current_streak=1;
        while(s.find(current_num+1)!=s.end()){
            current_num++;
            current_streak++;
        }
        longest_streak=max(longest_streak,current_streak);
        }
    }
    return longest_streak;
    }
};
