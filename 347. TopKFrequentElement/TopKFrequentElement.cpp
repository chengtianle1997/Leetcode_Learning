#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> result;
        if (nums.size() == 0 || k > nums.size())
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

}