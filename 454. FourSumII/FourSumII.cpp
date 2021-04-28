#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
        if (nums1.size() == 0 || nums2.size() == 0 || nums3.size() == 0 || nums4.size() < 0)
            return 0;
        int ResultCounter = 0;
        // we use a map to restore the A + B (key) and the counter of the sum (value)
        std::unordered_map<int, int> map;
        for (int& a : nums1)
        {
            for (int& b : nums2)
            {
                map[a + b]++;
            }
                
        }
        // check if -(C + D) in the map, if there is, add the value to the result counter
        for (int &c : nums3)
        {
            for (int &d : nums4)
            {
                if (map.find(-(c + d)) != map.end())
                    ResultCounter += map[-(c + d)];
            }
        }
        return ResultCounter;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums1 = {};
    std::vector<int> nums2 = {};
    std::vector<int> nums3 = {};
    std::vector<int> nums4 = {};
    std::cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << std::endl;

    nums1 = {1, 2};
    nums2 = {-2, -1};
    nums3 = {-1, 2};
    nums4 = {0, 2};
    std::cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << std::endl;

    nums1 = {0};
    nums2 = {0};
    nums3 = {0};
    nums4 = {0};
    std::cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << std::endl;
}