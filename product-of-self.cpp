#include <cstddef>
#include <new>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
	    vector<int> res(nums.size(), 1);
	    for (size_t i = 0; i < nums.size(); i++) {
	    	for (size_t j = 0; j < nums.size(); j++) {
			if (i == j)
				continue;
			res[i] *= nums[j];
		}
	    }
	    return res;
    }

    vector<int> productExceptSelf2(vector<int>& nums) {
	    int zeroCount = 0;
	    int product = 1;
	    for (const auto &num: nums) {
		    if (num == 0) {
			    zeroCount++;
		    } else {
			    product *= num;
		    }
	    }
	    if (zeroCount > 1)
		    return {0, static_cast<int>(nums.size())};
	    vector<int> result(nums.size());
	    for (size_t i = 0; i < nums.size(); i++) {
		    if (zeroCount > 0) {
			    result[i] = (nums[i] == 0) ? product : 0; // If not 0 then the product is already calculated
		    } else {
			    result[i] = product / nums[i]; // Remove the current element from the product by dividing.
		    }
	    }
	    return result;
    }
};

/*
 * Solution 1
 *
 * Brute force
 * Total time: O(n^2)
 * Total space: O(n)
 *
 * Solution 2
 *
 * Division
 * Total time: O(n)
 * Total space: O(n)
 */
