/*
˼·����2sum�ı������������o(n^2)��һ���㷨��������ڽ��Ҫ�������ظ��𰸣����¸��Ӷȵ���o(n^3)��������

��ʱ
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        map<int, int> maps;
        map<int, int>::iterator iter;
        int target;
        int c;

        for(int i=0; i<nums.size(); i++){
            target = 0 - nums[i];
            for(int j=0; j<nums.size(); j++){
                if(i == j)
                    continue;
                
                c = target - nums[j];
                if((iter = maps.find(c)) != maps.end()){
                    vector<int> answer1;
                    answer1.push_back(iter->first);
                    answer1.push_back(nums[j]);
                    answer1.push_back(nums[i]);
                    sort(answer1.begin(), answer1.end());
                    int k;
                    for(k=0; k<answer.size();k++){
                        if(answer1 == answer[k])
                            break;
                    }
                    if(k == answer.size())
                        answer.push_back(answer1);
                }
                maps[nums[j]] = j;
            }
            maps.clear();
        }
        return answer;
    }
}; 
