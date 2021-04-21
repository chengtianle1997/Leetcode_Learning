#include <iostream>
#include <vector>
#include <unordered_map>

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

void PrintResult(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;
    // test case 1: empty input
    std::vector<int> nums_a;
    int target_a = 0;
    auto result_a = solution.twoSum(nums_a, target_a);
    PrintResult(result_a);
    // test case 2: 
    std::vector<int> nums_b = {1, 2, 5, 3};
    int target_b = 5;
    auto result_b = solution.twoSum(nums_b, target_b);
    PrintResult(result_b);
}