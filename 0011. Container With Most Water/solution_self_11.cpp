/*
solution_self_11
˼·����򵥵�o(n^2)���㷨 
ִ����ʱ :1617 ms, ������ cpp �ύ�л�����19.30%���û�
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
