#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        // Method: Two pointers
        std::sort(nums.begin(), nums.end());

        // Find a + b + c = 0
        // Remember to remove the same cases:
        // nums[i] = nums[i - 1], if we use nums[i] = nums[i+1], we will ignore cases like [-1, -1, 2]
        // nums[left] = nums[left + 1], 
        // nums[right] = nums[right - 1].
        // The most initial point is recording the result before removing same cases.

        // Iterate 'a'(i)
        for (int i = 0; i < nums.size(); i++)
        {
            // if the first value is greater than 0, return result
            if (nums[i] > 0)
                return result;
            // 0 -- i -- left -- right -- end
            // remove the same cases
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    // a + b + c == 0 found!
                    result.push_back({ nums[i], nums[left], nums[right] });
                    // remove the same cases
                    // the same value on the right side
                    while (right > left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    // the same value on the left side
                    while (right > left && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    left++;
                    right--;
                }
            }
            
        }
        return result;
    }
};

void PrintResult(const std::vector<std::vector<int>> res)
{
    std::cout << "[ ";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << "[ ";
        for (int j = 0; j < res[i].size(); j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    Solution solution;
    // test case 1: empty vector
    std::vector<int> nums_a;
    auto res_a = solution.threeSum(nums_a);
    PrintResult(res_a);
    // test case 2: no success result
    std::vector<int> nums_b = {0, 1, 2, 3};
    auto res_b = solution.threeSum(nums_b);
    PrintResult(res_b);
    // test case 3: success result
    std::vector<int> nums_c = {-1, 0, 1, 2, -1, -4};
    auto res_c = solution.threeSum(nums_c);
    PrintResult(res_c);
    // test case 4: same value 0
    std::vector<int> nums_d = { 0, 0, 0, 0, 0, 0, 0 };
    auto res_d = solution.threeSum(nums_d);
    PrintResult(res_d);
}