#include <map>
#include <vector>
class Solution {
	using vector = std::vector<int>;
public:
    vector topKFrequent(vector& nums, int k) {
	std::map<int, int> mp;
	std::vector<vector> freq(nums.size() + 1);
	for (auto &num: nums) {
		if (mp.find(num) == mp.end()) {
			mp[num] = 1;
		} else {
			mp[num]++;
		}
	}
	for (const auto &elem: mp) {
		freq[elem.second].push_back(elem.first);
	}
	vector result;
	for (auto it = freq.rbegin(); it != freq.rend(); it++) {
		for (auto elem: *it) {
			result.push_back(elem);
			if (result.size() == k)
				return result;
		}
	}
	return result;
    }
};

/*
 * Solution 1
 *
 * iterate over all array elements and create a map based on num - frequency
 * create a vector of int vectors with the size of the numbers array and 
 * add to them each element based on their frequency. (Now they are in sorted order).
 * Iterate over the new vector in reverse order and on each subvector and add their
 * content to the result vector and return it.
 *
* Total Time : O(n)
* Total space : O(n)
 */
