/*
solution_self_9
˼·�������λ����Ȼ��ѭ���Խ��䷴�� 
ִ����ʱ :32 ms, ������ cpp �ύ�л�����19.17%���û�
*/ 

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int xt = x;
        // bug:������Щ�ӽ���int���޵�����������long�ᵼ���������ͬ��
        long n = 10;
        int m = 1;
        while(x / n != 0){
            n *= 10;
            m++;
        }
        long x2 = 0;
        for(int i=m-1; i>=0; i--){
            x2 += x / (long)pow(10, i) * (long)pow(10, m-1-i);
            x = x % (int)pow(10, i);
        }
        // cout << x2 << endl;
        if(xt == x2){
            return true;
        } else{
            return false;
        }
    }
};
