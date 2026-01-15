#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            int complement = target - currentNum;
            
            if (prevMap.find(complement) != prevMap.end()) {
                return {prevMap[complement], i};
            }
            prevMap[currentNum] = i;
        }
        
        return {};
    }
};