#include <unordered_map>
class Solution {
public:
    int ways(int n, std::unordered_map<int, int> &memo) {
	    if (n < 0)
		    return 0;
	    if (n == 0 || n == 1)
		    return 1;
	    if (memo.find(n) == memo.end()) {
		    memo[n] = ways(n - 1,memo) + ways(n - 2, memo);
	    }
	    return memo[n];
    }
    int climbStairs(int n) {
	    std::unordered_map<int,int> memo;
	    return ways(n, memo);
    }
};

/*
 * Solution
 *
 * Recursion with memoization
 *
 * we use recursion to understand all the possible ways that
 * we can reach to 0 from n by subtracting from each element
 * 1 and 2. If we reach 0 we add one to the total times else
 * 0. We use a map to cache results of specific numbers to not
 * repeat the calculations
 *
 * Total time: O(n)
 * Total space: O(n)
 *
 */
