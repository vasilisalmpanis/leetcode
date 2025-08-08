#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
	    int index = s.size() - 1;
	    int end = s.size() - 1;
	    while (end >= 0 && s[end] == ' ') {
		    end--;
	    }
	    index = end;
	    while (index >= 0 && s[index] != ' ') {
		    index--;
	    }
	    return end - index;
    }
};
