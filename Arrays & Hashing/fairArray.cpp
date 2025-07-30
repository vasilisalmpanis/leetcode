#include <vector>
using namespace std;
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
       int osum = 0; 
       int esum = 0;
       for (int i = 0; i < nums.size(); i++) {
	       if (i % 2 == 0)
		       esum += nums[i];
	       else
		       osum += nums[i];
       }

       int count = 0;
       for (int i = 0; i < nums.size(); i++) {
	       if (i % 2 == 0)
		       esum -= nums[i];
	       else
		       osum -= nums[i];
	       if (esum == osum)
		       count++;
	       if (i % 2 == 0)
		       esum += nums[i];
	       else
		       osum += nums[i];
       }
       return count;
    }
};
