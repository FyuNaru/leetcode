/*
����˼�룺��stack��map
ִ����ʱ :4 ms, ������ cpp �ύ�л�����74.26%���û�
�ڴ����� :8.4 MB, ������ cpp �ύ�л�����84.38%���û� 
*/
class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1)
            return false;
        //bug:δ���Ϊ��
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
                //bug��ջ��Ϊ��ʱ����top
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
