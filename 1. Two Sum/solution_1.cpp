/*
思路：map是用哈希表实现的，在哈希表中查询时为o(1)，每当访问过一个数组中的数时，都将其与下标存入map中，方便后续直接查找 
执行用时 :8 ms, 在所有 cpp 提交中击败了97.92%的用户
内存消耗 :10.1 MB, 在所有 cpp 提交中击败了34.51%的用户
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

 
