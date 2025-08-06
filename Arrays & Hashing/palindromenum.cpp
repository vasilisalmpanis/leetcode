#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
	    std::string num = std::to_string(x);       
	    if (num.empty())
		    return false;
	    int start = 0;
	    int end = num.size() - 1;
	    while (start <= end) {
		    if (num[start] != num[end])
			    return false;
		    start++;
		    end--;
	    }
	    return true;
    }
};

/*
 * Solution 
 *
 * 2 pointers
 *
 * convert the number into a string
 * hold pointer to start and to end.
 * check if the elemements are equal and
 * increment start and decrement end.
 *
 * Total time: O(n)
 * Total space: O(n)
 */
