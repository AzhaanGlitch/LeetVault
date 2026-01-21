#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        
        int targetIdx2 = total / 2;
        int targetIdx1 = targetIdx2 - 1;
        
        int i = 0, j = 0, count = 0;
        int val1 = 0, val2 = 0;
        
        while (count <= targetIdx2) {
            int currentVal;
            
            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                currentVal = nums1[i];
                i++;
            } else {
                currentVal = nums2[j];
                j++;
            }
            
            if (count == targetIdx1) val1 = currentVal;
            if (count == targetIdx2) val2 = currentVal;
            
            count++;
        }
        
        if (total % 2 == 0) {
            return (val1 + val2) / 2.0;
        } else {
            return (double)val2;
        }
    }
};