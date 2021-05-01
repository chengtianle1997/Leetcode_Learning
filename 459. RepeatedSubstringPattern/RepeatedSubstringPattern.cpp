#include <iostream>
#include <string>

class Solution_simple {
public:
    bool repeatedSubstringPattern(std::string s) {
        // if s does not have any repeated substring like:
        // a b c d 
        // then s + s is:
        // a b c d a b c d
        // we find string s(a b c d) from index 1 (the second element in the string),
        // it will return us the index of the first element for the second string,
        // which is exact equal to the size of string s.
        
        // if s have repeated substring like:
        // a a b a a b
        // then s + s is:
        // a a b a a b a a b a a b
        // we find string s(a a b a a b) from index 1 (the second element in the string),
        // it will return us the index of the first element for the second repeated substring,
        // which must be smaller than the size of string s.

        if (s.size() == 0)
            return false;
        return (s + s).find(s, 1) != s.size();
    }
};

// KMP Approach
class Solution {
public:

    // The cycle string with repeated substring like:
    // s1, s2, s3 ... sn
    // The largest equal prefix is s1, s2, s3 ... s[n-1]
    // The largest equal suffix is     s2, s3 ... s[n-1], s[n]
    // Then s.size() - prefix (or suffix).size() = the length of the repeated substring.
    // Therefore, if s.size() % the length of the repeated substring == 0,
    // the whole string s have the repeated cycle.

    void getNext(int* next, std::string& s)
    {
        // initializing
        int j = 0;
        next[0] = 0;
        // i is the tail of suffix, j is the tail of prefix
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
                j = next[j - 1];
            if (s[i] == s[j])
                j++;
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(std::string s)
    {
        if (s.size() == 0)
            return false;
        int* next = new int[s.size()];
        getNext(next, s);
        if (next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0)
            return true;
        return false;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.repeatedSubstringPattern("") << std::endl;
    std::cout << solution.repeatedSubstringPattern("abac") << std::endl; // remember to consider the case: next[last] == 0!
    std::cout << solution.repeatedSubstringPattern("abaaa") << std::endl;
    std::cout << solution.repeatedSubstringPattern("abcabcabc") << std::endl;
}
