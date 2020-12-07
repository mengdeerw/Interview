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
// Leetcode #2 Add Two Numbers
//https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *head = dummy;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            ListNode *curr = new ListNode(sum % 10);
            head->next = curr;
            head = head->next;
            
            // 继续下一个节点的计算
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummy->next;
    }
};
 
// 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii/
// 1. 计算两个链表所代表的数，相加后，再转换成链表
// 两数相加时可能会整型overflow
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        
        long long int num1 = 0, num2 = 0;
        while (l1) {
            num1 = num1*10 +  l1->val;
            l1 = l1->next;
        }
        
        while (l2) {
            num2 = num2*10 + l2->val;
            l2 = l2->next;
        }
        
        long long int sum = num1 + num2;
        ListNode *dummy = new ListNode(0), *head = dummy;
        if (sum == 0) return new ListNode(0);
        while (sum) {
            long long int digit = sum%10;
            sum /= 10;
            // insert to the front of list
            ListNode *curr = new ListNode(digit);
            curr->next = head->next;
            head->next = curr;
        }
        return dummy->next;
        
    }
};

// 2. using two stacks
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode *dummy = new ListNode(0), *head = dummy;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top(); s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top(); s2.pop();
            }
            carry = sum/10;
            
            ListNode *curr = new ListNode(sum%10);
            curr->next = head->next; // insertion to the front
            head->next = curr;
            
        }
        
        return dummy->next;
    }
};
