// https://leetcode.com/problems/sort-list/
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
// Merge Sort
// Time complexity: O(NlogN)
// Space complexity: O(logN) due to recursive call stack (depth of the recursion tree)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }
    
    // 1 2 3 4 5 null
    //     s      f
    //   s   f     
    ListNode* getMid(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* new_head = slow->next;
        slow->next = NULL; // 断开后半个链表
        return new_head;
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode *dummy = new ListNode(0), *curr = dummy;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        if (head1) curr->next = head1;
        if (head2) curr->next = head2;
        return dummy->next;
    }
};

// Quick Sort (OJ TLE)
// Time Complexity: Worst case: O(N^2) Average: O(NlogN)
// Space Complexity: worst case: O(N); average O(logN) (recusive stack tree depth)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        quickSort(head, tail);
        return head;
    }
    
    void quickSort(ListNode* head, ListNode* tail) {
        if (!head || head == tail) return; 
        ListNode *pivot = partition(head, tail);
        quickSort(head, pivot);
        quickSort(pivot->next, tail);
    }
    
    ListNode* partition(ListNode* head, ListNode* tail) {
        int pivot = head->val; //将list中的第一个节点作为pivot
        ListNode *pivotNode = head;
        ListNode *walker = head->next, *runner = head->next;
        while (runner && runner != tail->next) {
            // 一旦找到比pivot小的节点 就交换
            if (runner->val < pivot) {
                swap(walker, runner);
                walker = walker->next;
                pivotNode = pivotNode->next;
            }
            runner = runner->next;
        }
        swap(head, pivotNode);
        return pivotNode;
    }
    
    void swap(ListNode* A, ListNode* B) {
        int temp = A->val;
        A->val = B->val;
        B->val = temp;
    }
};
