#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int sum = 0;
        int min_size = INT_MAX;
        int i = 0;
        // i and j divide a sliding window which contains the subarray with sum >= target
        // loop j
        for (int j = 0; j < nums.size(); j++)
        {
            // expand the window
            sum += nums[j];
            // narrow the window and keep satisfying the condition
            while (sum >= target)
            {
                int sub_length = j - i + 1;
                min_size = sub_length < min_size ? sub_length : min_size;
                sum -= nums[i];
                i++;
            }
        }
        // if min_size has not been modified, return 0.
        return min_size < INT_MAX ? min_size : 0;
    }
};

int main()
{
    Solution solution;
    // test case 1: empty vector
    std::vector<int> nums_a;
    int target_a = 0;
    int res_a = solution.minSubArrayLen(target_a, nums_a);
    std::cout << res_a << std::endl;
    // test case 2: success result
    std::vector<int> nums_b = {2, 3, 1, 2, 4, 3};
    int target_b = 7;
    int res_b = solution.minSubArrayLen(target_b, nums_b);
    std::cout << res_b << std::endl;
    // test case 3: fail result
    std::vector<int> nums_c = {1, 2, 3, 1, 2, 1};
    int target_c = 11;
    int res_c = solution.minSubArrayLen(target_c, nums_c);
    std::cout << res_c << std::endl;
    // test case 4: success result
    std::vector<int> nums_d = { 1, 2, 3, 4, 5 };
    int target_d = 11;
    int res_d = solution.minSubArrayLen(target_d, nums_d);
    std::cout << res_d << std::endl;
}