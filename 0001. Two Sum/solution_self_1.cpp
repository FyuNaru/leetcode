/*
solution_self_1 
思路：暴力双重循环
184 ms
9.3 MB 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(target == nums[i] + nums[j]){
                    vec.push_back(i);
                    vec.push_back(j);
                    return vec;
                }
            }
        }
        return vec;
    }
};
