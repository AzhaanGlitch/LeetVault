#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        vector<int> answer(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                answer[i] = answer[i - 1] + 1; 
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {

                answer[i] = max(answer[i], answer[i + 1] + 1);
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += answer[i];
        }
        
        return sum;
    }
};