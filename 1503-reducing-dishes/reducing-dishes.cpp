#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int total_score = 0;
        int running_sum = 0;
        
        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            if (running_sum + satisfaction[i] > 0) {
                running_sum += satisfaction[i];
                total_score += running_sum;
            } else {
                break;
            }
        }
        
        return total_score;
    }
};