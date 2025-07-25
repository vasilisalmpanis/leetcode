#include <string>
#include <vector>
#include <map>
class Solution {
	using string = std::string;
public:
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
	std::vector<std::vector<string>> groupAnagrams(std::vector<string>& strs) {
		std::vector<std::vector<string>> result;
		for (auto &str : strs) {
			bool placed = false;
			for (auto &group : result) {
				if (isAnagram2(group[0], str)) {
					group.push_back(str);
					placed = true;
					break;
				}
			}
			if (!placed) {
				result.push_back({str});
			}
		}
		return result;
	}

	std::vector<std::vector<string>> groupAnagrams2(std::vector<string>& strs) {
		std::unordered_map<int, std::vector<string>> mp = {};
		for (auto &str: strs) {
			std::vector<int> count(26,0);
			for (char c : str) {
				count[c - 'a']++;
			}
			string key = to_string(count[0]);
			for (int i = 1; i < 26; i++) {
				key += "," + to_string(count[i]);
			}
			mp[key].push_back(str); // unique per anagram hashing key that stores the group vector
		}
		std::vector<std::vector<string>> result;
		for (const auto& pair: mp) {
			result.push_back(pair.second);
		}
		return result;
	}
};


/*
* Approach 1
* Use the anagram method from the prior assignment to determine
* if two given strings are anagrams of each other.
*
* if they are, push to the same vector else push them as new entry
* in the vector of anagrams.
* 
* Total : O(n * k)
* Total space : O(n * k)
*
* Approach 2
* We can do it faster by using an unordered map of frequency, vector<string>
* and in the end for each vector in the map add them to the result vector.
* 
* Total : O(n * k)
* Total space : O(n * k)
*/
