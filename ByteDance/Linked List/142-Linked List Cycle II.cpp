class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode* slow = head, *fast = head;
        bool isCycle = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
        // consider the case of [1]
        if (!isCycle) return NULL;
        
        fast = head;
        while (fast) {
            if (slow == fast) return slow; // if entry is at head
            slow = slow->next;
            fast = fast->next;
        }
        return NULL;
    }
};
