#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi)  // range define [lo, hi), so lo == hi is invalid.
        {
            // if target is in the range
            int mid = lo + (hi - lo) / 2; // to avoid overflow

            // in the right area
            if (nums[mid] < target)
            {
                lo = mid + 1; // attention: target may in range (mid, mid + 1£©
            }
            //  lo --- mid, (target), mid+1 --- hi
            //  -- --- mid, (target), lo  ----- hi
            // However, we have to assign at least one of the lo and hi to be mid + 1 or mid - 1 to make the cycle stop

            // in the left area
            else if (nums[mid] > target)
            {
                hi = mid; // target will not be missed
            }
            // lo --- (target), mid  --- hi
            // lo --- (target), hi   --- --

            // equal to the middle value
            else
            {
                return mid;
            }

            // Final case 1:
            // lo target hi
            // e.g:
            // lo(index:4) target hi(index:5) -> target < mid(index:4) -> lo = mid + 1 = 5
            // lo(index:5) target hi(index:5) -> return hi
            
            // Final case 2:
            // target lo hi
            // e.g:
            // target lo(index:4) hi(index:5) -> target < mid(index:4) -> lo = mid + 1 = 5
            // target lo(index:5) hi(index:5) -> return lo (hi)

            // Final case 3:
            // lo hi target
            // e.g:
            // lo(index:4) hi(index:5) target -> target > mid(index:4) -> hi = mid = 4
            // lo(index:4) hi(index:4) target(index->5) -> return hi+1
        }
        
        // Final case 2
        /*if (target < nums[lo])
            return lo;*/
        // Final case 3
        if (target > nums[hi])
            return hi + 1;
        // Final case 1 and 2
        return hi;
    }
};

int main()
{
    std::vector<int> test_0;
    int target_0 = 0;
    std::vector<int> test_a = {1, 3, 5, 6};
    int target_1 = 1;
    int target_2 = 4;
    int target_3 = 8;

    // test
    Solution solution;
    std::cout << solution.searchInsert(test_0, target_0) << std::endl;  // 0
    std::cout << solution.searchInsert(test_a, target_0) << std::endl;  // 0
    std::cout << solution.searchInsert(test_a, target_1) << std::endl;  // 0
    std::cout << solution.searchInsert(test_a, target_2) << std::endl;  // 2
    std::cout << solution.searchInsert(test_a, target_3) << std::endl;  // 4

    return 0;
}