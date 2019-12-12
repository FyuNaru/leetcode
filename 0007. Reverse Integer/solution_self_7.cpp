/*
solution_self_7
思路：先算出位数，然后循环以将其反向 
执行用时 :4 ms,时间分布只有三个区间，该程序处于第二区间 
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
            //发生了溢出
            return 0;
        } else{
            return x2;
        }
    }
};
