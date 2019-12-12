/*
solution_self_3
思路：一个o(n^2)的算法，从前往后依次遍历所有长度的子串，用set来判断是否有重复字符 
执行用时 :85 ms, 在所有 cpp 提交中击败了17.93%的用户 
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int pos;
        set<char> set;
        for(int i = 0; i< s.size(); i++){
            pos = s.find(s[i], i+1);//bug：此函数应从i+1开始查
            //cout << pos << endl;
            if(pos == string::npos){
                pos = s.size();
            }
            if((pos - i) <= max){
                continue;
            }
            for(int j = i; j < pos; j++){
                if(set.count(s[j]) == 0){
                    set.insert(s[j]);
                } else{
                    if((j - i) > max){
                        max = j - i;
                    }
                    break;
                }
            }
            // cout << set.size() << ":" << i << endl;
            if(set.size() == (pos - i)){
                max = pos - i;
                // cout << max << ":" << i << ":" << pos << endl;
            }
            set.clear(); // bug:忘记清空集合
        }
        return max;
    }
}; 
