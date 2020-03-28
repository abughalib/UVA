#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int p = -INFINITY, s = -INFINITY;

        for (int i = 0; i < nums.size(); i++) {
            s = nums[i] > s + nums[i] ? nums[i] : s + nums[i];
            p = p > s ? p : s;
        }
        return p;
    }
};

int main() {

    Solution sol;
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << sol.maxSubArray(nums);
    return 0;
}
