#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        if (nums.size() == 0)
        { 
            return result;
        }
        // hash map
        std::unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iterator = hash_map.find(target - nums[i]);
            if (iterator != hash_map.end())
            {
                result = { i, iterator->second };
                return result;
            }
            hash_map[nums[i]] = i;
        }
        return result;
    }
};

// Remember that:
// we will sort the array/vector in two pointers approach, and cannot get the indices of the original array
// if we want to get the indices, we may have to restore the indices and value into a map.
class Solution_pointers {
public:
    std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 2)
            return result;
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else // == target
            {
                // record result
                result.push_back({ nums[left], nums[right] });
                // remove the same cases
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                // update pointers
                left++;
                right--;
            }
        }
        return result;
    }
};

void PrintResult(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

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
    Solution_pointers solution_ptr;
    // test case 1: empty input
    std::vector<int> nums_a;
    int target_a = 0;
    auto result_a = solution.twoSum(nums_a, target_a);
    PrintResult(result_a);
    // test case 2: 
    std::vector<int> nums_b = {1, 2, 5, 3, 1};
    int target_b = 5;
    auto result_b = solution.twoSum(nums_b, target_b);
    PrintResult(result_b);

    // Two Pointers Approach
    // test case 1: empty input
    auto result_ap = solution_ptr.twoSum(nums_a, target_a);
    PrintResult(result_ap);
    // test case 2: only one valid answer
    auto result_bp = solution_ptr.twoSum(nums_b, target_b);
    PrintResult(result_bp);
    // test case 3: multiple valid answer
    std::vector<int> nums_c = { 2, 2, 2, 2 };
    int target_c = 4;
    auto result_c = solution_ptr.twoSum(nums_c, target_c);
    PrintResult(result_c);
}