#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        if (matrix.empty()) return result;

        int n = matrix.size();        // Number of rows
        int m = matrix[0].size();     // Number of columns

        int srow = 0, scol = 0;
        int erow = n - 1, ecol = m - 1;

        while (srow <= erow && scol <= ecol) {
            // 1. Top row
            for (int j = scol; j <= ecol; j++) {
                result.push_back(matrix[srow][j]);
            }

            // 2. Right column
            for (int i = srow + 1; i <= erow; i++) {
                result.push_back(matrix[i][ecol]);
            }

            // 3. Bottom row
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) { // Avoid duplicate row in single-row/middle case
                    break;
                }
                result.push_back(matrix[erow][j]);
            }

            // 4. Left column
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) { // Avoid duplicate column in single-col/middle case
                    break;
                }
                result.push_back(matrix[i][scol]);
            }

            // Shrink boundary
            srow++; scol++;
            erow--; ecol--;
        }

        return result;
    }
};