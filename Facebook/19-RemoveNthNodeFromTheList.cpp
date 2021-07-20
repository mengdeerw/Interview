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

// METHOD-1: two pass, one pointer
// 1. get length of the list
// 2. move pointer until it reaches len - n - 1
// 3. delete the next node
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pointer = head;
        int len = 0;
        // get length
        while (pointer) {
            pointer = pointer->next;
            len++;
        }
        // edge case
        if (len == n) return head->next;
        
        pointer = head;
        int i = len - n - 1;
        while (i) {
            pointer = pointer->next;
            i--;
        }
        pointer->next = pointer->next->next; // delete next node
        return head;
    }
};

// METHOD-2: one pass, two pointers
// slow and fast pointers
// let fast pointers to move n steps first, then move slow and fast pointers together until the fast pointer reach the end of the list
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // move fast to n + 1 element
        while (n) {
            fast = fast->next;
            n--;
        }
        if (!fast) return head->next;
        
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next; // remove
        return head;
    }
};
