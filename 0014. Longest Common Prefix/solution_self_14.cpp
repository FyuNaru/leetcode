/*
solution_self_14
˼·����򵥵�o(n^2)���㷨������Ч���������õ�һ���ַ����ĵ�i���ַ����κ������ַ����ĵ�i���ַ��Ƚ� 
ִ����ʱ :8 ms, ������ cpp �ύ�л�����65.88%���û�
*/ 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string answer;
        if(strs[0].size() == 0)
            return "";
        for(int j=0; j<strs[0].size();j++){
            answer += strs[0][j]; 
            for(int i=1; i<strs.size();i++){
                if(strs[i].find(answer) != 0){
                    answer.erase(answer.size()-1);
                    return answer;
                }
            }           
        }
        return answer;
    }
};
