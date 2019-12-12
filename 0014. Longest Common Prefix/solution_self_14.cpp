/*
solution_self_14
思路：最简单的o(n^2)的算法，但是效果还不错，拿第一个字符串的第i个字符依次和其他字符串的第i个字符比较 
执行用时 :8 ms, 在所有 cpp 提交中击败了65.88%的用户
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
