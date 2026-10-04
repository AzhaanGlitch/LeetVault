#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        int MOD = 1e9 + 7;
        vector<vector<int>> jumps = {
            {4, 6},      
            {6, 8},       
            {7, 9},      
            {4, 8},      
            {0, 3, 9},   
            {},           
            {0, 1, 7},    
            {2, 6},       
            {1, 3},       
            {2, 4}      
        };
        
        vector<long long> prev(10, 1);
        
        for (int step = 2; step <= n; step++) {
            vector<long long> curr(10, 0);
            
            for (int i = 0; i < 10; i++) {
                for (int next_digit : jumps[i]) {
                    curr[next_digit] = (curr[next_digit] + prev[i]) % MOD;
                }
            }
            
            prev = curr; 
        }
        
        long long total_ways = 0;
        for (int i = 0; i < 10; i++) {
            total_ways = (total_ways + prev[i]) % MOD;
        }
        
        return total_ways;
    }
};