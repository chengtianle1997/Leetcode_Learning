#include <iostream>
#include <string>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        // if ransomNote = "", magazine = "", return true!
        // we use a array to restore the counters for all lowercase letters
        int alpha[26] = { 0 };
        // count the string 'magazine'
        for (char &a : magazine)  // Note: use &a will achieve a higher performance (avoid copy)
            alpha[a - 'a']++;
        // check the ransomNote
        for (char &a : ransomNote)
        {
            // letter a has been restored
            if (alpha[a - 'a'] > 0)
            {
                // if there is no enough number of letter a: return false
                if (--alpha[a - 'a'] < 0)
                    return false;
            }
            // else : letter a has not been restored
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.canConstruct("", "") << std::endl;
    std::cout << solution.canConstruct("aa", "ab") << std::endl;
    std::cout << solution.canConstruct("aa", "aab") << std::endl;
}