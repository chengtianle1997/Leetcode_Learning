#include <iostream>
#include <vector>

class Solution {
public:
	/*
	int removeElement(std::vector<int>& nums, int val) {

		int p = 0, q = 0;

		// p record the end of new array
		// q record the start of old array
		// 0 -- (new array) -- p -- (target value) -- q -- (old array) -- end

		while (q < nums.size())
		{
			if (nums[q] == val) 
			{
				q++;
			}
			else
			{
				nums[p] = nums[q];
				p++;
				q++;
			}
		}
		// attention: nums[p] actually do not belong to the new array
		return p;
	}
	*/
	int removeElement(std::vector<int>& nums, int val) {\

		int left = 0, right = nums.size() - 1;
		
		// 0 --(new array) -- left ---(old array)--- right --(target value)-- end	
		// Notice: the left value and the right value are both not solved.

		while (left <= right) // left == right is the final case.
		{
			// if left value == target value, replace the left value with the right one.
			if (nums[left] == val)
			{
				nums[left] = nums[right];
				right--;
			}
			else
			{
				left++;
			}
		}
		// attention: nums[left] actually do not belong to the new array
		return left;
	}
};

void Printarray(const std::vector<int>& nums, int length)
{
	std::cout << "length: " << length << std::endl;
	for (int i = 0; i < length; i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	Solution solution;
	// test case 1: empty array
	std::vector<int> array_a;
	int val_a = 0;
	int length_a = solution.removeElement(array_a, val_a);
	Printarray(array_a, length_a);
	// test case 2: array without the assigned value
	std::vector<int> array_b = { 5, 4, 2, 3, 7, 1 };
	int val_b = 0;
	int length_b = solution.removeElement(array_b, val_b);
	Printarray(array_b, length_b);
	// test case 3: array with the assigned value
	std::vector<int> array_c = { 3, 2, 2, 3 };
	int val_c = 3;
	int length_c = solution.removeElement(array_c, val_c);
	Printarray(array_c, length_c);
	std::vector<int> array_d = { 0, 1, 2, 2, 3, 0, 4, 2 };
	int val_d = 2;
	int length_d = solution.removeElement(array_d, val_d);
	Printarray(array_d, length_d);
}