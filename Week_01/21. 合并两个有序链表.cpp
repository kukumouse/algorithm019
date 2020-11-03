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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2); //如果当前值小于l2的值 把链表下一个地址指向 l1->next 和 l2 之间 小的那个
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);//如果当前值小于l1的值 把链表下一个地址指向 l2->next 和 l1 之间 小的那个
            return l2;
        }

    }
};