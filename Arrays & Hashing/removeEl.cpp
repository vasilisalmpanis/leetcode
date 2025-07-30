#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
	int orig_size = nums.size();        
	int count = 0;
	vector<int>::iterator pos;
	while ((pos = find(nums.begin(), nums.end(), val)) != nums.end()) {
		count++;
		nums.erase(pos);
	}
	return orig_size - count;
    }
};

/*
 * Solution
 * we keep track of the initial size
 * and how many elements we remove and then
 * we return the difference of these numbers.
 *
 * Total time: O(n)
 * Total space: O(1)
 */
