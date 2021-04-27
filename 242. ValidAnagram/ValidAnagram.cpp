#include <iostream>
#include <string>

class Solution {
public:
	bool isAnagram(std::string s, std::string t)
	{
		if (s.size() == 0 || t.size() == 0 || s.size() != t.size())
			return false;
		const int capacity = 26;
		// letters counter for 'a' to 'z' 
		// (due to 's' and 't' only consists of lowercase letter)
		int alpha[capacity];
		// set all letters counter to 0
		for (int i = 0; i < capacity; i++)
			alpha[i] = 0;
		// record the letters in s
		for (int i = 0; i < s.size(); i++)
			alpha[s[i] - 'a']++;
		// check the letters in t
		for (int i = 0; i < t.size(); i++)
			alpha[t[i] - 'a']--;
		// check if there is difference
		for (int i = 0; i < capacity; i++)
		{
			if (alpha[i])
				return false;
		}
		return true;
	}
};

int main()
{
	Solution solution;
	std::cout << solution.isAnagram(std::string(""), std::string("")) << std::endl;
	std::cout << solution.isAnagram(std::string("anagram"), std::string("nagaram")) << std::endl;
	std::cout << solution.isAnagram(std::string("hat"), std::string("car")) << std::endl;
}