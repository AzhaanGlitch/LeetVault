#include <string>

using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int flips = 0;
        char status = '0';

        for (char ch : target) {
            if (ch != status) {
                flips++;
                status = ch;
            }
        }

        return flips;
    }
};