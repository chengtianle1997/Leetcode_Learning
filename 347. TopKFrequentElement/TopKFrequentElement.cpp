#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
private:
    class comparison {
    public:
        bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> result;
        if (nums.size() == 0 || k == 0 || k > nums.size())
            return result;
        // count the times in map: <nums[i], counter>
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) != map.end()) 
                map[nums[i]]++; 
            else
                map.insert({ nums[i], 1 });
        }
        // construct a min heap
        std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, comparison> pri_queue;
        // pair<int, int> means pair<nums[i], counter>
        // scan all element through a min heap with only K elements
        for (auto it = map.begin(); it != map.end(); it++)
        {
            pri_queue.push(*it);
            if (pri_queue.size() > k)
                pri_queue.pop(); // pop out the minimum one
        }
        // output the K frequent value
        for (int i = 0; i < k; i++)
        {
            result.push_back(pri_queue.top().first);
            pri_queue.pop();
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
    std::vector<int> nums = {};
    int k = 1;
    PrintResult(solution.topKFrequent(nums, k));
    nums = { 1,1,1,2,2,3 };
    k = 2;
    PrintResult(solution.topKFrequent(nums, k));
}