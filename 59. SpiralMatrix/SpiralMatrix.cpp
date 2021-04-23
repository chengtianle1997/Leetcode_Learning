#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        // define a 2D vector
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        if (n <= 0)
            return res;
        // let's define the border of unassigned block as left, top, right and bottom
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int num = 1;
        int target = n * n;
        while (num <= target)
        {
            // top line
            for (int i = left; i <= right; i++)
            {
                res[top][i] = num;
                num++;
            }
            top++;
            // right line
            for (int i = top; i <= bottom; i++)
            {
                res[i][right] = num;
                num++;
            }
            right--;
            // bottom line
            for (int i = right; i >= left; i--)
            {
                res[bottom][i] = num;
                num++;
            }
            bottom--;
            // left line
            for (int i = bottom; i >= top; i--)
            {
                res[i][left] = num;
                num++;
            }
            left++;
        }
        return res;
    }
};

void PrintResult(const std::vector<std::vector<int>>& result)
{
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

int main()
{
    Solution solution;
    // test case 1: n = 0
    auto res_a = solution.generateMatrix(0);
    PrintResult(res_a);
    // test case 2: n = 3
    auto res_b = solution.generateMatrix(3);
    PrintResult(res_b);
    // test case 3: n = 10
    auto res_c = solution.generateMatrix(10);
    PrintResult(res_c);
}