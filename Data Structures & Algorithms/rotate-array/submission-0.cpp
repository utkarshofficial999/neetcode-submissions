class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
         k=k%n;
        reverseSubarray(nums,0,n-1);
        reverseSubarray(nums,0,k-1);
        reverseSubarray(nums,k,n-1);
    }
    private :
    void reverseSubarray(vector<int>&nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
};