class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        return false;
    }
};
