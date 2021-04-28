#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        if (s.size() == 0)
            return;
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            // swap s[i] and s[j]
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

void PrintString(std::vector<char>& s)
{
    for (int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
}

int main()
{
    Solution solution;
    std::vector<char> s = {};
    solution.reverseString(s);
    PrintString(s);
    s = { 'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s);
    PrintString(s);
}