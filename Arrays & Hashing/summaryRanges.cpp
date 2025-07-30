#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
	vector<string> result;
    if (nums.size() == 0) {
        return result;
    }
	if (nums.size() == 1) {
		result.push_back(to_string(nums[0]));
		return result;
	}
	int start = nums[0];
	int current = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		current = nums[i];
		if (current != nums[i - 1] + 1) {
			if (start == nums[i-1]) {
				result.push_back(to_string(start));
			} else {
				result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
			}
			start = current;
		}
	}
    if (start == current)
        result.push_back(to_string(start));
    else
        result.push_back(to_string(start) + "->" + to_string(current));
	return result;
    }
};

/*
 * Solution
 *
 * We keep track of the beginning of the set
 * and the current element. If the set breaks
 * we insert the range from [start, nums[i - 1]]
 * else we continue the loop. when the for loop end
 * we still need to add the last range because it
 * was never added.
 *
 * Total time: O(n)
 * Total space: O(n)
 */
