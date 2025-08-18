#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
	    int start = 0;
	    int end = numbers.size() - 1;
	    while (start <= end) {
		    if (numbers[start] + numbers[end] == target) {
			    return {start + 1 , end + 1};
		    }
		    if (numbers[start] + numbers[end] < target) {
			    start++;
		    } else {
			    end--;
		    }
	    }
	    return {};
    }
};

/*
 * Solution
 *
 * We need to use a 2 pointer method
 * We are also not allowed to cache the result
 * which means we need to do it in O(1) space.
 * use start = 0 and end = size - 1. If the sum
 * is bigger than target this means that we need to add
 * something smaller which means decrementing end
 * The opposite applies for if the sum is bigger than the target.
 * In the end we either find the target and return the two indexes
 * or we return an empty vector.
 *
 * Total time: O(n)
 * Total space: O(1)
 */
