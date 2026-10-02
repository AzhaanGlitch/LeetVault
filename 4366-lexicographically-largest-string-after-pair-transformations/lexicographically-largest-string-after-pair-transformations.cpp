#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        
        for (long long x : nums) {
            string s = "";
            long long bit = 0;
            
            while (x > 0) {
                if (bit == 25) {
                    s.append(x, 'z');
                    break;
                }
                
                if (x & 1LL) {
                    s += (char)('a' + bit);
                }
                
                x >>= 1;
                bit++;
            }
            
            reverse(s.begin(), s.end());
            ans.push_back(s);
        }
        
        return ans;
    }
};