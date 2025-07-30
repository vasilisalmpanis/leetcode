#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	    int i = 0;
	    for (int j = 1; j < nums.size(); j++) {
		    if (nums[i] != nums[j]) {
			    i++;
			    nums[i] = nums[j];
		    }
	    }
	    return i + 1;
    }
};

/*
 * Solution
 *
 * We need to restructure the arrayw without actually removing the
 * elements from it just makign sure that all the unique elements are
 * places one after the other without duplicates and the length returned
 * is correct. We use two pointers. one that holds the current equal and
 * a cursor. when we find a new element that is not equal to the current
 * we copy new unique to the next spot.
 *
 * Total time: O(n)
 * Total space: O(1)
 */
