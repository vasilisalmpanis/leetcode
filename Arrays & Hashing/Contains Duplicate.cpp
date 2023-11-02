#include <vector>
#include <map>
#include <set>
#include <iostream>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
                return (true);
        }
        return (false);
    }
    bool containsDuplicate2(std::vector<int>& nums) {
        std::set<int> hello(nums.begin(), nums.end());
        return !(nums.size() == hello.size());
    }
};

/*
---------APPROACH 1------------
we sort the array using std::sort and then the duplicate elements will be
adjacent. Running a single loop comparing with the next value will tell us
if there are duplicates in our array.

Sorting complexity : O(nlogn)
Loop complexity : O(n)
Total time: O(nlogn)
Total space : O(1)

---------APPROACH 2------------
we create a set from the vector which removes duplicates from our array.
then using the member class methods size for comparison we can se if they
contain the same amount of elements 

Sorting complexity : O(nlogn)
Loop complexity : O(n)
Total : O(nlogn)
Total space : O(n)
*/