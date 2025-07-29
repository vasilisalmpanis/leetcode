#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
	int result = 0;
	for (const auto &num: nums) {
		int current = num, streak = 0;
		while (find(nums.begin(), nums.end(), current) != nums.end()) {
			current++;
			streak++;
		}
		result = max(result, streak);
	}
	return result;
    }
};

/*
 * Solution 1: Brute force
 *
 * Iterate over all elements and try to find the longest streak comparing it
 * with the previous longest and seving the result to return.
 *
 * Total time: O(n ^ 2)
 * Total space: O(1)
 */
