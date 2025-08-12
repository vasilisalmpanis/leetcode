#include <climits>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
	    int carry = 1;
	    for (int i = digits.size() - 1; i >= 0; i--) {
		if (carry == 0)
			break;
		if (digits[i] == 9) {
			digits[i] = 0;
			carry = 1;
		} else {
			digits[i]++;
			carry = 0;
		}
	    }
	    if (carry)
		    digits.insert(digits.begin(), 1);
	    return digits;
    }
};

/*
 * Solution
 *
 * Iterate from back to front and add 1 to the current element
 * if it reaches 10 we save the 0 and hold the carry. Next iteration
 * if there is no carry break the loop. In the end if there is still
 * a carry that means we need to insert 1 in the first position.
 *
 * Total time: O(n)
 * Total space: O(1)
 */
