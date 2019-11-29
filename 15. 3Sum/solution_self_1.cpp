/*
思路：由2sum改编而来，本来是o(n^2)的一个算法，结果由于结果要求不能有重复答案，导致复杂度到了o(n^3)甚至以上

超时
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
