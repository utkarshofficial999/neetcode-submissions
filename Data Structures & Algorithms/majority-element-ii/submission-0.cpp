class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1=0, cand2=0;
        int count1=0, count2=0;
     for (int num : nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) { // Add this: If slot 1 is empty
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) { // Add this: If slot 2 is empty
                cand2 = num;
                count2 = 1;
            } else {                 // Add this: Opposing vote against both
                count1--;
                count2--;
            }
        }
      count1 = 0;
        count2 = 0;

        // Count exact occurrences of our top two suspects
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }

        // 3. Collect the elements that cross the threshold
        vector<int> result;
        int threshold = nums.size() / 3;
        
        if (count1 > threshold) result.push_back(cand1);
        // Make sure cand2 isn't a duplicate of cand1 before adding it
        if (count2 > threshold && cand1 != cand2) result.push_back(cand2);

        return result ; 
    }
};