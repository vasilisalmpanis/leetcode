#include <map>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
	    // row hashset
	    map<int, set<char>> row;
	    map<int, set<char>> column;
	    map<pair<int,int>, set<char>> squares;
	    for (int i = 0; i < 9; i++) {
	    	for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.')
				continue;
			pair<int,int> index = {i / 3, j / 3};
			if (row[i].count(board[i][j]) 
					|| column[j].count(board[i][j])
					|| squares[index].count(board[i][j])
			   )
				return false;
			row[i].insert(board[i][j]);
			column[j].insert(board[i][j]);
			squares[index].insert(board[i][j]);
		}
	    }
	    return true;
    }
};

/*
 * Solution 1
 * We hold sets for each row and column and check the counts of elements. if they are more than one we return false
 * we create maps of row,column index holding the sub 3x3 squares and create the keys by dividing row, column by 3.
 * Time complexity: O(n^2)
 * Space complexity: O(n^2)
 */
