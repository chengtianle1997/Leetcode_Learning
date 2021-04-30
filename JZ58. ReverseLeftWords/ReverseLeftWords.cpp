#include <iostream>
#include <string>

// in-location approach
class Solution {
public:
    void reverse(std::string& s, int start, int end)
    {
        int left = start, right = end;
        while (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    std::string reverseLeftWords(std::string s, int n) {
        if (s.size() == 0 || n < 1 || n >= s.size())
            return s;
        // Step 1: Reverse the first n elements [0, (n - 1)]
        reverse(s, 0, n - 1);
        // Step 2: Reverse the elements from n + 1 to end [n, size - 1]
        reverse(s, n, s.size() - 1);
        // Step 3: Reverse the whole string
        reverse(s, 0, s.size() - 1);
        return s;
    }
};

class Solution_simple {
public:
    std::string reverseLeftWords(std::string s, int n)
    {
        if (s.size() == 0 || n < 1 || n >= s.size())
            return s;
        return s.substr(n) + s.substr(0, n);
    }

};

int main()
{
    Solution solution;
    std::cout << solution.reverseLeftWords("", 1) << std::endl;
    std::cout << solution.reverseLeftWords("abcdefg", 2) << std::endl;
    std::cout << solution.reverseLeftWords("lrloseumgh", 6) << std::endl;
}