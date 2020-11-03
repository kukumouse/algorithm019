class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;//记录0下标地址
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0 && nums[j] != 0)
            {
                j = i;
            }
            if (nums[i] != 0 && i != j)
            {
                if (nums[j] == 0)
                {
                    nums[j] = nums[i];
                    nums[i] = 0;
                    for (int first_zero = j+1 ; first_zero < nums.size() ; first_zero++)
                        if (nums[first_zero] == 0)
                        { 
                            j = first_zero;
                            break;
                        }
                }
            }
        }
    }
};

//官方优解
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
    }
};

//记录非0值下标
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0 ;
        for (int i =0;i<nums.size();i++)
        {
            if(nums[i] != 0 )
            {
                nums[j] = nums[i];
                if (j!=i)
                {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
};