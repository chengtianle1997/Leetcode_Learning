#include <iostream>
#include <stack>

// use a stack
class Solution_slow {
public:
    std::string removeDuplicates(std::string S) {
        std::stack<char> pStack;
        int i = 0;
        while (i < S.size())
        {
            if (!pStack.empty() && S[i] == pStack.top())
            {
                pStack.pop();
            }
            else 
            {
                pStack.push(S[i]);
            }
            i++;
        }
        S.resize(pStack.size());
        for (int j = pStack.size() - 1; j >= 0; j--)
        {
            S[j] = pStack.top();
            pStack.pop();
        }
        return S;
    }
};

// use the string as the stack: faster, beat 99%
class Solution {
public:
    std::string removeDuplicates(std::string S)
    {
        std::string result;
        for (char& a : S)
        {
            if (result.empty() || a != result.back())
                result.push_back(a);
            else
                result.pop_back();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.removeDuplicates("abbaca") << std::endl;
    std::cout << solution.removeDuplicates("aaaaa") << std::endl;
}