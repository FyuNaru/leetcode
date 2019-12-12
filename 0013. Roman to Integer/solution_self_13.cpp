/*
solution_self_13
思路：一层循环switch直接解，考虑下一个字符和当前字符组合的情况 
执行用时 :12 ms, 在所有 cpp 提交中击败了92。59%的用户
*/ 

class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            switch(s[i]){
                case 'I':{
                    if((i+1)<n && (s[i+1] == 'V' || s[i+1] == 'X')){
                        answer += -1;
                    } else{
                        answer += 1;
                    }
                    break;
                }
                case 'V':{
                    answer += 5;
                    break;
                }
                case 'X':{
                    if((i+1)<n && (s[i+1] == 'L' || s[i+1] == 'C')){
                        answer += -10;
                    } else{
                        answer += 10;
                    }
                    break;
                }
                case 'L':{
                    answer += 50;
                    break;
                }
                case 'C':{
                    if((i+1)<n && (s[i+1] == 'D' || s[i+1] == 'M')){
                        answer += -100;
                    } else{
                        answer += 100;
                    }
                    break;
                }
                case 'D':{
                    answer += 500;
                    break;
                }
                case 'M':{
                    answer += 1000;
                    break;
                }
            }
        }
        return answer;
    }
};
