#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

class Solution_simple {
public:
    bool isValid(std::string s) {
        std::stack<char> pStack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                pStack.push(s[i]);
            if (s[i] == ')')
            {
                if (!pStack.empty() && pStack.top() == '(')
                    pStack.pop();
                else
                    return false;
            }
            else if (s[i] == ']')
            {
                if (!pStack.empty() && pStack.top() == '[')
                    pStack.pop();
                else
                    return false;
            }
            else if (s[i] == '}')
            {
                if (!pStack.empty() && pStack.top() == '{')
                    pStack.pop();
                else
                    return false;
            }
        }
        return pStack.empty();
    }
};

// With unordered_map: beat 100%
class Solution {
public:
    bool isValid(std::string s) {
        int n = s.size();
        // the string s only contains the parentheses
        if (n % 2 == 1)
            return false;
        // parentheses pairs
        std::unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        std::stack<char> pStack;
        for (char& a : s)
        {
            if (pairs.count(a))
            {
                if (pStack.empty() || pStack.top() != pairs[a])
                    return false;
                pStack.pop();
            }
            else
            {
                pStack.push(a);
            }
        }
        return pStack.empty();
    }
};

int main()
{
    Solution solution;
    std::cout << solution.isValid(std::string("")) << std::endl;
    std::cout << solution.isValid(std::string("()")) << std::endl;
    std::cout << solution.isValid(std::string("([)")) << std::endl;
    std::cout << solution.isValid(std::string(")")) << std::endl;
}