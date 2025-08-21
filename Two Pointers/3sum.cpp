#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0)
			break;
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		int start = i + 1;
		int end = nums.size() - 1;
		while (start < end) {
			int sum = nums[i] + nums[start] + nums[end];
			if (sum > 0)
				end--;
			else if (sum < 0)
				start++;
			else {
				result.push_back({nums[i], nums[start], nums[end]});
				start++;
				end--;
				while (start < end && nums[start] == nums[start - 1]) {
					start++;	
				}
			}
		}
	}
	return result;
    }
};

