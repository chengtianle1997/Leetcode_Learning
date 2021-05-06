#include <iostream>
#include <vector>
#include <deque>

class Solution {
private:
    class MyQueue {
        // maintain a structure that contains every possible values of maximum:
        // 1. The value in the queue is in the same order of the input vector.
        // 2. The front value in the queue is always the maximum.
    public:
        void pop(int value)
        {
            // pop if the value is exact the first value of the queue
            if (!m_deque.empty() && value == m_deque.front())
                m_deque.pop_front();
        }
        void push(int value)
        {
            // if value is larger than the tail value, pop_back the tail
            while (!m_deque.empty() && value > m_deque.back())
                m_deque.pop_back();
            m_deque.push_back(value);
        }
        // return the max element of queue
        int front()
        {
            return m_deque.front();
        }
    private:
        std::deque<int> m_deque;
    };
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        if (nums.size() == 0 || k > nums.size())
            return result;
        MyQueue queue;
        for (int i = 0; i < k; i++)
        {
            queue.push(nums[i]);
        }
        // record the maximum of the first k element
        result.push_back(queue.front());
        // Sliding start
        for (int i = k; i < nums.size(); i++)
        {
            queue.pop(nums[i - k]);
            queue.push(nums[i]);
            result.push_back(queue.front());
        }
        return result;
    }
};

void PrintResult(std::vector<int> result)
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
    std::vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    PrintResult(solution.maxSlidingWindow(nums, 3));
}