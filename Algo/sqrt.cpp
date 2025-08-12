#include <cinttypes>
#include <cmath>
class Solution {
public:
    int mySqrt(int x) {
	    unsigned int start = 1;
	    unsigned int end = x;
	    unsigned int mid;
	    if (x == 0 || x == 1)
		    return x;
	    while (start <= end) {
		    mid = start + (end - start) / 2;
		    long long mul = static_cast<long long>(mid) * mid;
		    if (mul == x) {
			    return mid;
		    }
		    if (mul > x) {
			    end = mid - 1;
		    } else {
			    start = mid + 1;
		    }
	    }
	    return static_cast<int>(std::round(end));
    }
};

/*
 * Solution
 *
 * We use binary search. The normal implementation of binary search is
 * 1. start from 0 till end.
 * 2. calc mid by mid = start + (end - start) / 2;
 * 3. compare mid with target. If smaller add to start else remove from end
 *
 * Total time: O(log n)
 * Total space: O(1)
 */
