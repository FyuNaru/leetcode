/*
solution_self_11
思路：最简单的o(n^2)的算法 
执行用时 :1617 ms, 在所有 cpp 提交中击败了19.30%的用户
*/ 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int temp = 0;
        for(int i=0; i < height.size()-1; i++){
            for(int j=i+1; j < height.size(); j++){
                if((temp = min(height[i], height[j]) * (j-i)) > max)
                    max = temp;
            }
        }
        return max;
    }
};
