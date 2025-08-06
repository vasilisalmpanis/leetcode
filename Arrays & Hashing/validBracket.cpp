#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
	    std::vector<char> stack;
	    for (const auto &c: s) {
		    if (c == '(' || c == '{' || c == '[')
			    stack.push_back(c);
		    else {
			    if (stack.empty() || (stack.back() == '(' && c != ')') 
					    || (stack.back() == '{' && c != '}')
					    || (stack.back() == '[' && c != ']')
				)
				    return false;
			    stack.pop_back();
		    }
	    }
	    return stack.empty();
    }
};

/*
 * Solution
 *
 * use a stack
 *
 * keep adding the opening parenthesis to the stack and pop the element if the correct closing
 * one appears. If at the end the stack is empty the parenthesis are valid.
 *
 * Total time: O(n)
 * Total space O(n)
 *
 */
