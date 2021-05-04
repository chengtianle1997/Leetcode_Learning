#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    // The RPN has two characteristics
    // 1. when we get a number, push it into the stack
    // 2. when we get an operator, pop two number from the top of the stack and calculate the result
    //    and push it into the stack
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> pStack;
        std::unordered_set<std::string> operators = { "+", "-", "*", "/" };
        for (std::string& s : tokens)
        {
            // if we get a opearator
            if (operators.find(s) != operators.end())
            {
                // invalid operation
                if (pStack.size() < 2)
                    return 0;
                int opr_a = pStack.top();
                pStack.pop();
                int opr_b = pStack.top();
                pStack.pop();
                if (s == "+")
                    pStack.push(opr_b + opr_a);
                if (s == "-")
                    pStack.push(opr_b - opr_a);
                if (s == "*")
                    pStack.push(opr_b * opr_a);
                if (s == "/")
                    pStack.push(opr_b / opr_a);
            }
            // if we get a number
            else
            {
                pStack.push(atoi(s.c_str()));
            }
        }
        if (pStack.size() == 1)
            return pStack.top();
        else
            return 0;
    }
};

int main()
{
    Solution solution;
    std::vector<std::string> tokens = { "2", "1", "+", "3", "*" };
    std::cout << solution.evalRPN(tokens) << std::endl;
}