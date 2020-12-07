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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = head, *post = dummy;
        post->next = pre;
        
        for (int i = 0; i < m - 1; i++) {
            post = pre;
            pre = pre->next;
        }
        
        for (int i = 0; i < n - m; i++) {
            ListNode *curr = pre->next;
            pre->next = curr->next;
            curr->next = post->next;
            post->next = curr;
        }
        return dummy->next;
    }
};
