#include <algorithm>
#include <map>
#include <string>

class Solution {
public:
	using string = std::string;
	bool isAnagram(string s, string t) {
		if (s.length() != t.length())
			return false;
		std::sort(s.begin(), s.end());
		std::sort(t.begin(), t.end());
		return s != t;
	}
	bool isAnagram2(string s, string t) {
		std::map<char, int> cache1;
		std::map<char, int> cache2;
		if (s.size() != t.size())
			return false;
		for (int i = 0; i < s.size(); i++) {
			auto pos = cache1.find(s[i]);
			if (pos == cache1.end())
				cache1[s[i]] = 1;
			else {
				pos->second = pos->second += 1;	
			}
			pos = cache2.find(t[i]);
			if (pos == cache2.end())
				cache2[t[i]] = 1;
			else {
				pos->second = pos->second += 1;	
			}
		}
		return cache1 == cache2;
	}
};

/*
# Approach 1
we sort the strings using std::sort and then check that the
strings are equal.

Sorting complexity : O(nlogn + mlogm)
Total time: O(nlogn)
Total space : O(1)

---------APPROACH 2------------
We use a hashmap to store each character and the frequency of its
appearance for both strings. If both maps are equal then we have a valid
anagram.

Total : O(n + m)
Total space : O(1)
*/
