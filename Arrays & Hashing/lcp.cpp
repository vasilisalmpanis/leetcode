#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin(), strs.end()); 
       int minLength = min(strs.front().size(), strs.back().size());
       int common_pos = 0;
       int i = 0;
       while( i < minLength && strs.front()[i] == strs.back()[i]) {
	       i++;
       }
       string result = strs.front().substr(0, i);
       return result;
    }
};

/*
 * Solution
 *
 * sort the array of string and find the longest prefix between the first and last
 * this will be for all the in between.
 *
 * Total time: O(nlogn)
 * Total space: O(1)
 */
