/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/* Two pass iteration
1. find the length of the list
2. swap in groups
*/
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int length = 1;
        while (head && head->next) {
            length++;
            head = head->next;
        }
        ListNode *pre = dummy;
        for (int l = 0; l + k <= length; l += k) {
            ListNode* cur = pre->next;
            ListNode* nxt = cur->next;
            for (int i = 1; i < k; ++i) {
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next; //将nxt指向下一次遍历
            }
            pre = cur;
        }
        return dummy->next;
    }
};
