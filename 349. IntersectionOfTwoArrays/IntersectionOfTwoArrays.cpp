#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    // two sets: beat 1%
    std::vector<int> intersection_slow(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0)
            return result;
        // ensure to restore the smaller vector to unordered_set
        if (nums1.size() > nums2.size())
        {
            // swap nums1 and nums2
            std::vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        // restore nums1 to the unordered_set
        std::unordered_set<int> set(nums1.begin(), nums1.end());
        // restore result
        std::unordered_set<int> res_set;
        // find element
        for (int num : nums2)
        {
            // if we find the element in set
            if (set.find(num) != set.end())
            {
                res_set.insert(num);
            }
        }
        // output the res_set to result vector
        result = std::vector<int>(res_set.begin(), res_set.end());
        return result;
    }

    // Two pointers in two vectors: beat 62%
    std::vector<int> intersection_faster(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0)
            return result;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else // nums1 == nums2
            {
                result.push_back(nums1[i]);
                i++;
                j++;
                // remove the same results
                while (i < nums1.size() && nums1[i] == nums1[i - 1])
                    i++;
                while (j < nums2.size() && nums2[j] == nums2[j - 1])
                    j++;
            }
        }
        return result;
    }

    // simple array hash table: beat 90%+
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0)
            return result;
        // due to the constraints that:
        // 1 <= nums1.length, nums2.length <= 1000
        // 0 <= nums1[i], nums2[i] <= 1000
        int alpha[1001] = { 0 };
        // record nums1
        for (int num : nums1)
        {
            alpha[num]++;
        }
        // check nums2
        for (int num : nums2)
        {
            // num exists in alpha set
            if (alpha[num])
            {
                result.push_back(num);
                // avoid same result
                alpha[num] = 0;
            }
        }
        return result;
    }
};

void PrintResult(std::vector<int>& result)
{
    for (int value : result)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;
    std::vector<int> nums1 = {};
    std::vector<int> nums2 = {};
    auto result = solution.intersection(nums1, nums2);
    PrintResult(result);
    nums1 = { 1, 2, 2, 1 };
    nums2 = { 2, 2 };
    result = solution.intersection(nums1, nums2);
    PrintResult(result);
    nums1 = { 4, 9, 5 };
    nums2 = { 9, 4, 9, 8, 4 };
    result = solution.intersection(nums1, nums2);
    PrintResult(result);
}