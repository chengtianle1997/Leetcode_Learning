#include <iostream>
#include <string>

// Let's make it a O(1) space algorithm, which means a in-location move.

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

    std::string reverseWords(std::string s) {
        if (s.size() == 0)
            return s;

        // Step 1: Remove extra space
        // Two pointers: fast pointer and slow pointer
        int slow = 0, fast = 0;
        // remove the space on the head
        while (s[fast] == ' ')
        {
            fast++;
        }
        while (fast < s.size())
        {
            // if space found
            if (s[fast] == ' ')
            {
                s[slow] = s[fast];
                slow++;
                fast++;
                // if continuous space appears
                while (s[fast] == ' ')
                    fast++;
            }
            else
            {
                s[slow] = s[fast];
                slow++;
                fast++;
            }
        }
        // check if the tail is a space (slow is the pointer after the tail now, so --slow)
        if (s[--slow] == ' ' && slow > 1)
            slow--;
        // now, slow points to the last element
        // resize the string
        s.resize(slow + 1);

        // Step 2: Reverse the whole string
        reverse(s, 0, slow);

        // Step 3: Reverse every single word
        int p = 0;
        for (int q = 0; q < s.size(); q++)
        {
            // find a new word
            if (s[q] == ' ')
            {
                reverse(s, p, q - 1); // we have ensured that the first element is not a space
                p = q + 1; // we have ensured that there will not be continuous space, so p is the start of the next word
            }
        }
        // reverse the last word
        reverse(s, p, s.size() - 1); // we have ensured that there will not be a space as the last element

        return s;
    }
};

int main()
{
    Solution solution;
    std::string s = "";
    std::cout << solution.reverseWords(s) << "|--end" << std::endl;
    s = "the sky is blue";
    std::cout << solution.reverseWords(s) << "|--end" << std::endl;
    // Reverse string should not contain leading or trailing spaces
    s = "  hello world ";
    std::cout << solution.reverseWords(s) << "|--end" << std::endl;
    // Reduce multiple spaces between two words to a single space
    s = "a good  example";
    std::cout << solution.reverseWords(s) << "|--end" << std::endl;
    s = "Alice does not even like Bob ";
    std::cout << solution.reverseWords(s) << "|--end" << std::endl;
}