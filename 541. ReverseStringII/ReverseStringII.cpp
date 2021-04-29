#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        if (s.size() == 0 || k == 0 || k == 1)
            return s;
        for (int n = 0; 2 * k * n < s.size() - 1; n++)
        {
            int left = 2 * k * n;
            int right = std::min(left + k - 1, (int)(s.size() - 1)); // Remember: the last item is s.size() - 1
            while (left < right)
            {
                // swap
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        return s;
    }
};

int main()
{
    Solution solution;
    std::string s = "";
    int k = 0;
    std::cout << solution.reverseStr(s, k) << std::endl;
    s = "abcdefg";
    k = 2;
    std::cout << solution.reverseStr(s, k) << std::endl;
    s = "abcd";
    k = 2;
    std::cout << solution.reverseStr(s, k) << std::endl;
    s = "abcdefg";
    k = 8;
    std::cout << solution.reverseStr(s, k) << std::endl;
}