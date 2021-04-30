#include <iostream>
#include <string>

// This is the classical example for KMP algorithm

class Solution {
public:
    void getNext(int* next, std::string& s)
    {
        // next table restores the callback position of each element,
        // which is decided by the max length of the equal head(prefix) and tail(suffix) substring.
        // e.g.: if the needle is "aabaaf"
        //    substring    the max length
        //        a              0
        //       aa              1   for head 'a' == tail 'a'
        //      aab              0
        //      aaba             1   for head 'a' == tail 'a'
        //      aabaa            2   for head 'aa' == tail 'aa'
        //      aabaaf           0

        // so the next table is [0, 1, 0, 1, 2]

        // initialize
        // j is the element after tail of the prefix, and j is also the length of prefix string
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            // i is the last element of the whole substring
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1]; // call back j
            }
            if (s[j] == s[i])
                j++;
            next[i] = j;
        }
    }
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() == 0)
            return 0;
        // Get next table (prefix table)
        int* next = new int[needle.size()];
        getNext(next, needle);
        // Scan the string
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            // if mismatching, call back j
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            // if matching, go compare the next position
            if (haystack[i] == needle[j])
                j++;
            // if comparing finished, return index
            if (j >= needle.size())
                return i - needle.size() + 1;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.strStr("", "") << std::endl;
    std::cout << solution.strStr("hello", "ll") << std::endl;
    std::cout << solution.strStr("aaaaa", "aa") << std::endl;
    std::cout << solution.strStr("aaaaa", "aab") << std::endl;
    std::cout << solution.strStr("aabaabaaf", "aabaaf") << std::endl;
}
