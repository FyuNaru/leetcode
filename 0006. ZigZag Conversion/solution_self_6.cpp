/*
solution_self_6
思路：算下标的方法解出来的，同样时间略有些长 ，不过相比于第四题来说超时不算很多，在可接受范围内 
执行用时 :172 ms, 在所有 cpp 提交中击败了100%的用户
*/ 

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows){
            string answer(s);
            return s;
        }
        //确定最终矩阵的长宽
        int A = s.size() / (2*numRows-2);
        int B = s.size() % (2*numRows-2);
        if(B != 0)
            A++;
        int matrix[numRows][A * (numRows-1)];
        for(int i=0; i<numRows; i++){
            for(int j=0; j<A*(numRows-1); j++){
                matrix[i][j] = -1;
            }
        }
        //将字符对应的下标填入矩阵
        //用以决定某个字符在矩阵中的下标
        int x;
        //用以决定第几个z型，并确定下标
        int a = 0;
        for(int i=0; i<s.size(); i++){
            x = (i+1) % (2*numRows-2);
            if(x == 0){
                a = a + numRows - 1;
                matrix[1][a-1] = i;
            } else if( x >= 1 && x <= numRows - 1){
                matrix[x-1][a] = i;
                // cout << (x-1) << " " << a << endl;
            } else{
                matrix[(numRows-1)-(x-numRows)][a+(x-numRows)] = i;
                // cout << ((numRows-1)-(x-numRows)) << " " << a+(x-numRows) << endl;
            }
        }

        string answer;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<A*(numRows-1); j++){
                if(matrix[i][j] != -1){
                    answer += s[matrix[i][j]];
                }
            }
        }
        return answer;
    }
};
