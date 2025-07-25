#include <string>
#include <vector>
#include <cstdlib>
class Solution {
	using string = std::string;
public:

    string encode(std::vector<string>& strs) {
	string res;
	for (const auto&str: strs) {
		res += std::to_string(str.size()) + "#" + str;
	}
	return res;
    }

    std::vector<string> decode(string s) {
	    std::vector<string> res;
	    size_t pos = 0;
	    std::string token;
	    while ((pos = s.find("#")) != std::string::npos) {
		    int length = atoi(s.substr(0, pos).c_str());
		    s.erase(0, pos + 1);
		    string content = s.substr(0, length);
		    res.push_back(content);
		    s.erase(0, length);
	    }
	    return res;
    }
};

/*
 * Solution
 *
 * we create a new string with a delimiter seperating the size and the content.
 * then to decode we parse the string, get the length and the content and continue
 * from pos = beggining of string + length.
 *
 * Total time: O(m);
 * Total space: O(m + n);
 * m = sum of lefths of all strings.
 * n = number of strings
 */
