/*
solution_2
˼·�������ԭ���Լ�д�Ĵ��룬�������������Ż���
1.ͨ����ǰ�����ķ�ʽ���϶̵�һ��list���ɺͽϳ���һ��ͬ���ĳ��ȣ��Ӷ����ö���д�����ظ��Ĵ��� 
2.ͨ��Ϊ���յĽ�������һ��ͷ������ʽ�����Բ�����ѭ��֮ǰ�ȼ����һ���ڵ� 
ִ����ʱ :20 ms, ������ cpp �ύ�л�����98.20%���û�
�ڴ����� :10.3 MB, ������ cpp �ύ�л�����90.19%���û�
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
        // ��ʼ��
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
