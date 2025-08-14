#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	    vector<int> result;
	    int i = 0;
	    int j = 0;
	    int index = 0;
	    if (n == 0)
		    return ;
	    while (index < n + m) {
		    if (i == m) {
			    result.push_back(nums2[j]);
			    j++;
		    } else if (j == n) {
			    result.push_back(nums1[i]);
			    i++;
		    } else {
			    if (nums1[i] < nums2[j] && i < m) {
				    result.push_back(nums1[i]);
				    i++;
			    } else {
				    result.push_back(nums2[j]);
				    j++;
			    }
		    }
		    index++;
	    }
	    for (int u = 0; u < n + m; u++) {
		    nums1[u] = result[u];
	    }
    }
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	    if (n == 0)
		    return ;
	    int end_1 = m - 1;
	    int end_2 = n - 1;
	    int end_index = n + m - 1;
	    while (end_1 > 0 && end_2 > 0) {
		    if (nums2[end_2] > nums1[end_1]) {
			    nums1[end_index] = nums2[end_2];
			    end_2--;
		    } else {
			    nums1[end_index] = nums1[end_1];
			    end_1--;
		    }
		    end_index--;
	    }
	    while (end_2 >= 0) {
		nums1[end_index] = nums2[end_2];
		end_2--;
		end_index--;
	    }
    }
};

/*
 * Solution 1
 *
 * 2 Passes
 *
 * Create a new vector
 * loop over elements and put them in sorted order
 * copy from new to old
 *
 * Total time: O(2 * (n + m))
 * Total space: O(n + m)
 *
 * Solution 2
 *
 * double pointer
 *
 * Add elements from back to front since the bigger ones
 * are always in the end by keepign pointers to the next element
 * in the array to compare and add any leftover elements in nums2
 *
 * Total time: O(n + m)
 * Total space: O(1)
 */
