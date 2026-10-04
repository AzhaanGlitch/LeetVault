class Solution {
public:
    int knightDialer(int n) {
        int MOD = 1e9 + 7;
        
        int jumps[10][3] = {
            {4, 6, -1},
            {6, 8, -1},
            {7, 9, -1},
            {4, 8, -1},
            {0, 3, 9},
            {-1, -1, -1},
            {0, 1, 7},
            {2, 6, -1},
            {1, 3, -1},
            {2, 4, -1}
        };
        
        long long prev[10];
        long long curr[10];
        
        for (int i = 0; i < 10; i++) {
            prev[i] = 1;
        }
        
        for (int step = 2; step <= n; step++) {
            for (int i = 0; i < 10; i++) {
                curr[i] = 0;
            }
            
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 3; j++) {
                    int next_digit = jumps[i][j];
                    if (next_digit == -1) break;
                    
                    curr[next_digit] = (curr[next_digit] + prev[i]) % MOD;
                }
            }
            
            for (int i = 0; i < 10; i++) {
                prev[i] = curr[i];
            }
        }
        
        long long total_ways = 0;
        for (int i = 0; i < 10; i++) {
            total_ways = (total_ways + prev[i]) % MOD;
        }
        
        return total_ways;
    }
};