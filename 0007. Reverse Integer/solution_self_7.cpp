/*
solution_self_7
˼·�������λ����Ȼ��ѭ���Խ��䷴�� 
ִ����ʱ :4 ms,ʱ��ֲ�ֻ���������䣬�ó����ڵڶ����� 
*/ 

class Solution {
public:
    int reverse(int x) {
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
        if(x2 < -pow(2, 31) || x2 > pow(2, 31) - 1){
            //���������
            return 0;
        } else{
            return x2;
        }
    }
};
