/*
反转LinkedList 4种算法:
-迭代反转法
-递归反转法
-就地逆置
-头插法
递归反转法更适用于反转不带头节点的链表；其它 3 种方法既能反转不带头节点的链表，也能反转带头节点的链表。
详细：http://c.biancheng.net/view/8105.html
*/
//所谓头插法，是指在原有链表的基础上，依次将位于链表头部的节点摘下，然后采用从头部插入的方式生成一个新链表，则此链表即为原链表的反转版。
// 头插法：
// 每次将原链表的头摘下，插入到新链表的表头
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *new_head = NULL;
        while (head) {
            //用temp记下原链表head
            ListNode *temp = head;
            //将temp从原链表的head中摘除
            head = head->next;
            //将temp插入新链表头部new_head
            temp->next = new_head;
            new_head = temp;
        }
        return new_head;      
    }
};

//就地逆置法反转链表
//就地逆置法和头插法的实现思想类似，唯一的区别在于，头插法是通过建立一个新链表实现的，而就地逆置法则是直接对原链表做修改，从而实现将原链表反转。
//值得一提的是，在原链表的基础上做修改，需要额外借助 2 个指针
//  head----->1----->2----->3----->4
//  --------begin---end-----
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *begin = head, *end = head->next;
        while (end) {
            //先摘除end pointer所指的节点 (将节点2与原链表断链)
            begin->next = end->next;
            // 添加end至链表头部，每次都需要调整head所指的位置(指向新的头节点)
            end->next = head;
            head = end;
            // 调整end的指向，为反转下一个节点做准备
            end = begin->next;
        }
        return head;
    }
};

// 递归法
// 递归反转法的实现思想是从链表的尾节点开始，依次向前遍历，遍历过程依次改变各节点的指向，即另其指向前一个节点。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        // 一直递归，直到找到链表的最后一个节点
        ListNode* new_head = reverseList(head->next);
        // 从后向前逐层退出，new_head指向一直不变，指向原链表的最后一个节点；而head指针则指向上一个节点
        // 每退出一层，都需改变head->next节点的指向，并使head节点的指向域变为NULL
        head->next->next = head;
        head->next = NULL;
        // 每一层递归结束，都要将新表头new_head返回给上一层，保证能够一直找到新链表表头
        return new_head;
    }
};

