#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int max_green = 0;
        for (int l : lights) {
            max_green = max(max_green, l);
        }
        
        int max_waiting_time = 0;
        
        for (int time : arrivalTime) {
            int r = time % period;
            
            if (r >= max_green) {
                int wait_time = period - r;
                max_waiting_time = max(max_waiting_time, wait_time);
            }
        }
        
        return max_waiting_time;
    }
};