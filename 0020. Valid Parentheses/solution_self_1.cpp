/*
基本思想：用stack和map
执行用时 :4 ms, 在所有 cpp 提交中击败了74.26%的用户
内存消耗 :8.4 MB, 在所有 cpp 提交中击败了84.38%的用户 
*/
class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1)
            return false;
        //bug:未检查为空
        if(s == "")
            return true;
        stack<char> stack;
        map<char, char> map;
        map.insert(pair<char, char>('(', ')'));
        map.insert(pair<char, char>('[', ']'));
        map.insert(pair<char, char>('{', '}'));

        stack.push(s[0]);
        // cout << "push" << s[0] << endl;
        for(int i=1; i<s.size(); i++){
            if(stack.empty() == false && s[i] == map[stack.top()]){
                //bug：栈不为空时才有top
                stack.pop();
                // cout << "pop" << s[i] << endl;
            } else{
                stack.push(s[i]);
                // cout << "push" << s[i] << endl;
            }
        }
        if(stack.empty())
            return true;
        else
            return false;
    }
};
