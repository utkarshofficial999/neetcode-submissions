#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        
        // 1. Combine position and speed into pairs
        std::vector<std::pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        
        // 2. Sort by position in descending order (closest to target first)
        std::sort(cars.rbegin(), cars.rend());
        
        int fleetCount = 0;
        double maxTime = 0.0;
        
        // 3. Process each car
        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            
            // If this car takes LONGER than the lead fleet ahead, it starts a new fleet
            if (time > maxTime) {
                fleetCount++;
                maxTime = time; // Update the bottleneck time for cars behind
            }
        }
        
        return fleetCount;
    }
};