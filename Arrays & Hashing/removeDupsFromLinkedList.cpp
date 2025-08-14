// struct ListNode {
// 	int val;
// 	ListNode *next;
// 	ListNode() : val(0), next(nullptr) {}
// 	ListNode(int x) : val(x), next(nullptr) {}
// 	ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
	    if (head == nullptr)
		    return head;
	    ListNode *curr = head;
	    while (curr) {
		    if (curr->next && curr->next->val == curr->val) {
			    curr->next = curr->next->next;
			    continue;
		    }
		    curr = curr->next;
	    }
	    return head;
    }
};

/**
 * Solution
 *
 * Single pointer. Keep a pointer to the current element
 * if the next element exists and has the same value as the current
 * change curr->next to curr->next->next and redo the loop for the next element
 * else move to the next element for comparison since the list is sorted.
 *
 * Total time: O(n)
 * Total space: O(1)
 */
