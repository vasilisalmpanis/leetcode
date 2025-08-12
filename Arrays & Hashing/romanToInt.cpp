#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
	int result = 0;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		switch (s.at(i)) {
			case 'I':
				if (i < size - 1 && s.at(i + 1) == 'V') {
					result += 4;
					i++;
				} else if (i < size - 1 && s.at(i + 1) == 'X') {
					result += 9;
					i++;
				} else {
					result += 1;
				}
				break;
			case 'V':
				result += 5;
				break;
			case 'X':
				if (i < size - 1 && s.at(i + 1) == 'L') {
					result += 40;
					i++;
				} else if (i < size - 1 && s.at(i + 1) == 'C') {
					result += 90;
					i++;
				} else {
					result += 10;
				}
				break;
			case 'L':
				result += 50;
				break;
			case 'C':
				if (i < size - 1 && s.at(i + 1) == 'D') {
					result += 400;
					i++;
				} else if (i < size - 1 && s.at(i + 1) == 'M') {
					result += 900;
					i++;
				} else {
					result += 100;
				}
				break;
			case 'D':
				result += 500;
				break;
			case 'M':
				result += 1000;
				break;
			default:
				break;
		}
	}
	return result;
    }
};

/*
 * Solution
 *
 * Just follow the instructions and convert using a simple
 * switch statement.
 *
 * Total time: O(n)
 * Total space: O(1)
 *
 */
