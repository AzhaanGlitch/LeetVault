#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        vector<int> neg;
        vector<int> pos;

        for (int i = 0; i < satisfaction.size(); i++) {
            if (satisfaction[i] >= 0) {
                pos.push_back(satisfaction[i]);
            } else {
                neg.push_back(satisfaction[i]);
            }
        }

        int temp = 0;
        for (int i = 0; i < pos.size(); i++) {
            temp += pos[i];
        }

        vector<int> chosen_neg;
        for (int i = neg.size() - 1; i >= 0; i--) {
            if (temp + neg[i] > 0) {
                chosen_neg.push_back(neg[i]);
                temp += neg[i];
            } else {
                break;
            }
        }

        reverse(chosen_neg.begin(), chosen_neg.end());

        vector<int> final_dishes;
        for (int i = 0; i < chosen_neg.size(); i++) {
            final_dishes.push_back(chosen_neg[i]);
        }
        for (int i = 0; i < pos.size(); i++) {
            final_dishes.push_back(pos[i]);
        }

        int result = 0;
        for (int i = 0; i < final_dishes.size(); i++) {
            result += final_dishes[i] * (i + 1);
        }

        return result;
    }
};