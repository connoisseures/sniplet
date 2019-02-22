//21. Merge Two Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*
        case1
           124
        l1:   |
           134
        l2:  |
           1234
        crt:  |
        
        */
        ListNode dmy(0);
        ListNode* crt = &dmy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                crt->next = l1;
                l1 = l1->next;
            } else {
                crt->next = l2;
                l2 = l2->next;
            }
            crt = crt->next;
        }
        if (l1) crt->next = l1;
        if (l2) crt->next = l2;
        return dmy.next;
    }
};
