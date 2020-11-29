class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0 , right = nums.size() - 1;
        int mid = 0 ;
        while (left < right){
            mid = (left + right) / 2;
            if (nums[0] <= nums[mid] && (target > nums[mid] || target < nums[0])){
                left = mid + 1;
            }else if(target < nums[0] && target > nums[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
            
        }
        return left == right && nums[left] == target ? left : -1;
    }
};