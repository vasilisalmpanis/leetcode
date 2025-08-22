#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& heights) {
	int maxWater = 0;        
	int start = 0;
	int end = heights.size() - 1;
	while (start < end) {
		int min_height = std::min(heights[start], heights[end]);
		int waterArea = min_height * (end - start);
		maxWater = std::max(waterArea, maxWater);
		if (heights[start] <= heights[end])
			start++;
		else
			end--;
	}
	return maxWater;
    }
};


/*
 * Previously done for leetcode
 *
 * We use the two pointer solution instead of bruteforcing
 * we start from 0 and size - 1. We calculate the water
 * size of the current pair and update our max water
 * we want to have the biggest set of heights so we update
 * start and end according to which element is smaller on that
 * particular index.
 *
 * Total time: O(n)
 * Total space: O(1)
 */
