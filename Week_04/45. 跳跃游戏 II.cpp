class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0 ;
        int maxNumber = 0 ;
        int step = 0;
        for (int i = 0 ; i < nums.size() - 1 ; i++){
            maxNumber = max(i+nums[i],maxNumber);
            if (i == end){
                end = maxNumber;
                step++;
            }
        }
        return step;
    }
};