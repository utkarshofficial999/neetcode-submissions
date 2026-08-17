class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int l = 0;
        int r = 0;

        for(int weight : weights) {
            l = max(l, weight);
            r += weight;
        }

        while(l <= r) {

            int m = (l + r) / 2;

            int daysNeeded = 1;
            int currentWeight = 0;

            for(int weight : weights) {

                if(currentWeight + weight > m) {
                    daysNeeded++;
                    currentWeight = 0;
                }

                currentWeight += weight;
            }

            if(daysNeeded <= days) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return l;
    }
};