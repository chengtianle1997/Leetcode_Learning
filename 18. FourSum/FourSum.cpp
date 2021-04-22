#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 4)
            return result;
        // sort items
        std::sort(nums.begin(), nums.end());
        // iterate i
        for (int i = 0; i < nums.size(); i++)
        {
            // remove the same cases
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // iterate j
            for (int j = i + 1; j < nums.size(); j++)
            {
                // remove the same cases: remember do not remove the first item of for loop
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // two pointers
                int left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if ( sum > target)
                        right--;
                    else if (sum < target)
                        left++;
                    else // == target
                    {
                        // record the result
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        // remove the same cases
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        // update pointers
                        left++;
                        right--;
                    }
                }

            }
        }
        return result;
    }
};

void PrintResult(const std::vector<std::vector<int>>& result)
{
    std::cout << "[ ";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << "[ ";
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << "] ";
    }
    std::cout << "] " << std::endl;
}

int main()
{
    Solution solution;
    // test case 1: empty vector
    std::vector<int> nums_a = {0, 0, 0};
    int target_a = 0;
    auto res_a = solution.fourSum(nums_a, target_a);
    PrintResult(res_a);
    // test case 2: no success result
    std::vector<int> nums_b = { 1, 0, -1, 0, -2, -2, 2 };
    int target_b = 4;
    auto res_b = solution.fourSum(nums_b, target_b);
    PrintResult(res_b);
    // test case 3: success result
    std::vector<int> nums_c = { 1, 0, -1, 0, -2, -2, -2, 2 };
    int target_c = 0;
    auto res_c = solution.fourSum(nums_c, target_c);
    PrintResult(res_c);
    // test case 4: vector with same values
    std::vector<int> nums_d = { 2, 2, 2, 2, 2 };
    int target_d = 8;
    auto res_d = solution.fourSum(nums_d, target_d);
    PrintResult(res_d);
}