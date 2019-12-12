/*
solution_self_6
˼·�����±�ķ���������ģ�ͬ��ʱ������Щ�� ����������ڵ�������˵��ʱ����ܶ࣬�ڿɽ��ܷ�Χ�� 
ִ����ʱ :172 ms, ������ cpp �ύ�л�����100%���û�
*/ 

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows){
            string answer(s);
            return s;
        }
        //ȷ�����վ���ĳ���
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
        //���ַ���Ӧ���±��������
        //���Ծ���ĳ���ַ��ھ����е��±�
        int x;
        //���Ծ����ڼ���z�ͣ���ȷ���±�
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
