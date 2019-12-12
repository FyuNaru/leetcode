/*
˼·��map���ù�ϣ��ʵ�ֵģ��ڹ�ϣ���в�ѯʱΪo(1)��ÿ�����ʹ�һ�������е���ʱ�����������±����map�У��������ֱ�Ӳ��� 
ִ����ʱ :8 ms, ������ cpp �ύ�л�����97.92%���û�
�ڴ����� :10.1 MB, ������ cpp �ύ�л�����34.51%���û�
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> maps;
        map<int,int>::iterator iter;
        vector<int> answer;
        maps[nums[0]] = 0;
        int c;
        for(int i=1; i<nums.size(); i++){
            c = target - nums[i];
            if((iter = maps.find(c)) != maps.end()){
                answer.push_back(iter->second);
                answer.push_back(i);
                return answer;
            }
            maps[nums[i]] = i;
        }
        return answer;
    }
};

 
