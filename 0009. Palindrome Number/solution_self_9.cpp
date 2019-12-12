/*
solution_self_9
思路：先算出位数，然后循环以将其反向 
执行用时 :32 ms, 在所有 cpp 提交中击败了19.17%的用户
*/ 

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int xt = x;
        // bug:对于那些接近于int上限的数，不声明long会导致溢出，下同。
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
