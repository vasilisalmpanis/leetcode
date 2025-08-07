#include <string>
using namespace std;

class Solution {
	public:
		int strStr(string haystack, string needle) {
			for (int i = 0; i < haystack.size(); i++) {
				int curr = 0;
				if (needle.empty())
					continue;      
				while (haystack[i + curr] && haystack[i + curr] == needle[curr])
					curr++;
				if (curr == needle.size()) return i;
			}
			return -1;
		}
};

/*
 * Solution
 *
 * Run a loop for every character in a string
 * start comparing with the needle. as soon as they are
 * unequal stop comparing and check length. if the length
 * is equal to the needle's length we found a match.
 *
 * Total time: O(n^2)?
 * Total time: O(1)
 */
