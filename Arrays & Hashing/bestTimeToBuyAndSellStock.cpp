#include <vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int min = prices[0];
		int profit = 0;
		for(const auto &price: prices) {
			if (price < min) {
				min = price;
			}
			int temp_profit = price - min;
			if (temp_profit > profit) {
				profit = temp_profit;
			}
		}
		return profit;
	}
};

/*
 * Solution
 *
 * Hold min price, max profit and return
 * the profit in the end
 *
 * Total time: O(n)
 * Total space: O(1)
 */
