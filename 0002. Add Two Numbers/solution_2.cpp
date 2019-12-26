/*
solution_2
思路：针对于原来自己写的代码，做了如下两个优化：
1.通过在前面加零的方式将较短的一个list补成和较长的一个同样的长度，从而不用额外写两段重复的代码 
2.通过为最终的结果链表加一个头部的形式，可以不用在循环之前先计算第一个节点 
执行用时 :20 ms, 在所有 cpp 提交中击败了98.20%的用户
内存消耗 :10.3 MB, 在所有 cpp 提交中击败了90.19%的用户
*/ 


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 初始化
        int c = 0;
        ListNode *answer = new ListNode(0);
        ListNode *p = answer;
        int x;
        int y;
        int n;
        while(l1 != NULL || l2 != NULL){
            x = l1 == NULL? 0:l1->val;
            y = l2 == NULL? 0:l2->val;
            n = x + y + c;
            c = n/10;
            n = n%10;
            p->next = new ListNode(n);
            p = p->next;
            l1 = l1 == NULL? NULL:l1->next;
            l2 = l2 == NULL? NULL:l2->next;
        }
        if(c == 1){
            p->next = new ListNode(c);
        }
        return answer->next;
    }
};
