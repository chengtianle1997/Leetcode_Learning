#include <iostream>
#include <string>

class Solution {
public:
    std::string replaceSpace(std::string s) {
        if (s.size() == 0)
            return s;
        // count the number of space
        int counter = 0;
        for (char& a : s)
        {
            if (a == ' ')
                counter++;
        }
        // resize the string to the new size
        int oldSize = s.size();
        int newSize = oldSize + 2 * counter;
        s.resize(newSize);
        // fill the string from the end
        // Here, why not fill the string from the start?
        // because filling from start is a O(n^2) solution,
        // which means we have to move all the element behind the insertion point,
        // and filling from end is a O(n) solution.

        // Two pointers approach: p from the new end, q from the old end
        int p = newSize - 1;
        int q = oldSize - 1;
        while (q < p) // we do not need the condition: p >=0, because the end case must be q == p
        {
            if (s[q] == ' ')
            {
                s[p--] = '0';
                s[p--] = '2';
                s[p--] = '%';
                q--;
            }
            else
            {
                s[p] = s[q];
                p--;
                q--;
            }
        }
        return s;
    }
};

int main()
{
    Solution solution;
    std::string s = "We Are Happy.";
    std::cout << solution.replaceSpace(s) << std::endl;
}