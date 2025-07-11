#include <map>
#include <vector>

/**
 * @class Solution
 * @brief 2Sum
 *
 * This algorithm is meant to get a vector of numbers and a target
 * and return the indexes of the numbers that if added gives us the target
 * we could do it with bruteforcing by checking all possible pairs of numbers O(n ^ 2)
 * Best solution is we keep a hashmaps of values and indexes. we calculate the difference
 * of current number with target and lookit up in our hashmap. if it exists we return the indexes
 * if not we add it to the hashmap and continue with the next element.
 * Space O(n)
 * Time O(n)
 */
class Solution {
public:
	using vector=std::vector<int>;
	vector twoSum(vector &nums, int target) {
		std::map<int,int> cache;
		vector result;
		for (int i = 0; i < nums.size(); i++) {
			int diff = target - nums[i];
			auto pos = cache.find(diff);
			if (pos == cache.end()) {
				cache[nums[i]] = i;
			} else {
				result.push_back(pos->second);
				result.push_back(i);
				return result;
			}
		}
		return result;
	}
};
