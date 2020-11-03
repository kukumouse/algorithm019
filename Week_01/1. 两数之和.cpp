//梦开始的地方，hash解法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for (int i = 0 ;i< nums.size();i++)
        {
           auto it = hashmap.find(target-nums[i]);
           if (it != hashmap.end())
           {
               return {it->second,i};
           }
           hashmap[nums[i]] = i;
        }
        return {};
    }
};