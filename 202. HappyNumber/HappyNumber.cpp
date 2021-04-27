#include <iostream>
#include <unordered_set>

// using unordered_set
class Solution_set {
public:
    // Get the sum of squared single number
    int getSum(int value)
    {
        int sum_t = 0;
        while (value)
        {
            sum_t += (value % 10) * (value % 10);
            value = value / 10;
        }
        return sum_t;
    }
    bool isHappy(int n) {
        std::unordered_set<int> sum_set;
        int sum = n;
        while (sum != 1)
        {
            sum = getSum(sum);
            if (sum_set.find(sum) != sum_set.end())
                // find the same result
                return false;
            sum_set.insert(sum);
        }
        return true;
    }
};

// using two pointers: fast pointer and slow pointer
class Solution {
public:
    int getSum(int value)
    {
        int sum_t = 0;
        while (value)
        {
            sum_t += (value % 10) * (value % 10);
            value = value / 10;
        }
        return sum_t;
    }

    bool isHappy(int n)
    {
        int fast = n, slow = n;
        do
        {
            // fast pointer go 2 step
            fast = getSum(fast);
            fast = getSum(fast);
            // slow pointer go 1 step
            slow = getSum(slow);
        } while (fast != slow);
        // if fast == slow, there is a cycle
        // if fast == slow == 1, it is a happy num
        return fast == 1;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.isHappy(19) << std::endl;
    std::cout << solution.isHappy(2) << std::endl;
}