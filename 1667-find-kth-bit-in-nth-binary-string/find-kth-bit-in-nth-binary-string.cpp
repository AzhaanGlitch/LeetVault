#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    string invertAndReverse(string s) {
        for (char &c : s) {
            c = (c == '0') ? '1' : '0';
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    char findKthBit(int n, int k) {
        string current = "0";
        for (int i = 2; i <= n; i++) {
            current = current + "1" + invertAndReverse(current);
        }
        return current[k - 1];
    }
};