#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
	    int start = 0;
	    int end = s.size() - 1;
	    while (start <= end) {
		    if (!std::isalnum(s[start])) {
			    start++;
			    continue;
		    }
		    if (!std::isalnum(s[end])) {
			    end--;
			    continue;
		    }
		    if (std::tolower(s[start]) != std::tolower(s[end]))
			    return false;
		    start++;
		    end--;
	    }
	    return true;
    }
};
