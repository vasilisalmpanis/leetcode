#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
	int left = 0;        
	int right = height.size() - 1;
	int maxArea = (right - left) * min(height[left], height[right]);
	while (left < right) {
		int currentArea = (right - left) * max(height[left], height[right]);
		if (currentArea > maxArea) {
			maxArea = currentArea;
		}
		if (height[left] < height[right]) {
			left++;
		} else {
			right--;
		}
	}
	return maxArea;
    }
};

/*
 * Solution
 *
 * We use the two pointer approach. we have a pointer to the 
 * left side and one to the right size of the array. We calculate
 * the area and if the current area is bigger than the maxArea we 
 * save the new value. We then compare heights and move the one with
 * the smallest height to the next position.
 *
 * Total time: O(n)
 * Total space: O(1)
 */
