#include <algorithm>
#include <climits>
#include <ios>
#include <vector>
using namespace std;
class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			const int combined_size = nums1.size() + nums2.size();
			vector<int> merged;
			merged.reserve(combined_size);       
			for (const auto&num: nums1) {
				merged.push_back(num);
			}
			for (const auto&num: nums2) {
				merged.push_back(num);
			}
			sort(merged.begin(), merged.end(), [](int a, int b) {
					return a < b;
					});
			if (combined_size % 2) {
				return merged[combined_size / 2];
			} else {
				return (double(merged[combined_size / 2 - 1]) + double(merged[combined_size / 2])) / 2;
			}
		}
		double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
			if (nums1.size() > nums2.size())
				return findMedianSortedArrays2(nums2, nums1);

			int n = nums1.size();
			int m = nums2.size();
			int total = n + m;
			int half = ( total + 1 ) / 2;

			int lo = 0;
			int high = n;

			// we perform binary search on the two arrays without merging
			// we take the smaller one and start from 0 to size
			// we keep two pointers. we calculate the middle (lo + high) / 2
			// and the middle of the bigger array by subtractin the mid1 from half
			// we calculate left and right of each array and compare. if valid
			// we return the median else we need to modify lo and high accordingly.
			while (lo <= high) {
				int mid1 = (lo + high) / 2;
				int mid2 = half - mid1;

				int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
				int r1 = (mid1 == n) ? INT_MAX : nums1[mid1];

				int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
				int r2 = (mid2 == m) ? INT_MAX : nums2[mid2];

				if (l1 <= r2 && l2 <= r1) {
					if (total % 2 == 0) {
						return (max(l1, l2) + min(r1, r2)) / 2.0;
					} else {
						return max(l1, l2);
					}
				} else if (l1 > r2) {
					high = mid1 - 1;
				} else {
					lo = mid1 + 1;
				}
			}

			return 0.0; // Should never reach here if inputs are valid
		}
};

/*
 * Solution 1
 *
 * Create a merged vector, sort it and calculate the median.
 * Total Time: O(nlogn)
 * Total space: O(n + m)
 */
