#include <cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        
        for (int i = 0; i <= 30; i++) {
            long long power = pow(2, i);
            
            if (power == n) {
                return true;
            }
            if (power > n) {
                return false;
            }
        }
        return false;
    }
};