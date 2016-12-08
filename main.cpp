#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class solution {
public:
    int missingNumber(const std::vector<int> & nums) {
	std::vector<int> temp = nums;
	for (int i = 0; i < temp.size(); i++)
	    if (i != temp[i] && temp[i] != nums.size())
		std::swap(temp[i], temp[temp[i]]);
	std::cout << "After swapping:\n";
	std::copy(temp.begin(), temp.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
	for (int i = 0; i < temp.size(); i++)
	    if (temp[i] != i)
		return i;
	return nums.size();
    }
};

int main() {
    std::vector<int> nums{1,0,2,5,3,4,7,8};

    solution soln;
    int missing = soln.missingNumber(nums);
    std::cout << "The missing number is:\n"
	      << missing << std::endl;
}
