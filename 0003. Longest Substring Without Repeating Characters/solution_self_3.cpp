/*
solution_self_3
˼·��һ��o(n^2)���㷨����ǰ�������α������г��ȵ��Ӵ�����set���ж��Ƿ����ظ��ַ� 
ִ����ʱ :85 ms, ������ cpp �ύ�л�����17.93%���û� 
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int pos;
        set<char> set;
        for(int i = 0; i< s.size(); i++){
            pos = s.find(s[i], i+1);//bug���˺���Ӧ��i+1��ʼ��
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
            set.clear(); // bug:������ռ���
        }
        return max;
    }
}; 
