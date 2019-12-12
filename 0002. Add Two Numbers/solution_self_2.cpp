/*
solution_self_2
思路：类似于曾经数据结构课程中多项式相加的题目
执行用时 :35 ms, 在所有 cpp 提交中击败了40.27%的用户
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
        int n = l1->val + l2->val;
        //c表示进位
        int c = 0;
        if(n >= 10){
            n = n - 10;
            c = 1;
        }
        ListNode *result = new ListNode(n);
        ListNode *p = result;
        while(l1->next != NULL && l2->next != NULL){
            l1 = l1->next;
            l2 = l2->next;
            n = c == 1? l1->val + l2->val + 1 : l1->val + l2->val;
            if(n >= 10){
                n = n - 10;
                c = 1;
            } else{
                c = 0;
            }
            p->next = new ListNode(n);
            p = p->next;
        }
        if(l1->next == NULL){
            while(l2->next != NULL){
                p->next = l2->next;
                p = p->next;
                l2 = l2->next;
                if(c == 1){
                    n = p->val + 1;
                    if(n >= 10){
                        n = n - 10;
                        c = 1;
                    } else{
                        c = 0;
                    }
                    p->val = n;
                }
            }
        }
        if(l2->next == NULL){
            while(l1->next != NULL){
                p->next = l1->next;
                p = p->next;
                l1 = l1->next;
                if(c == 1){
                    n = p->val + 1;
                    if(n >= 10){
                        n = n - 10;
                        c = 1;
                    } else{
                        c = 0;
                    }
                    p->val = n;
                }
            }
        }
        if(c == 1){
            p->next = new ListNode(1);
        }
        return result;
    }
};
