class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int len = nums.size();
        vector<bool> used(len,false);
        sort(nums.begin(),nums.end());
        dfs (nums,ans,path,used);
        return ans;
    }
    void dfs(vector<int>& nums,vector<vector<int>>& ans,vector<int>& path,vector<bool>& used){
        if (path.size() == nums.size()){
            ans.push_back(path);
            return ;
        }
        for (int i = 0 ; i < nums.size();i++){
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && used[i-1]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums,ans,path,used);
            path.pop_back();
            used[i] = false;
        }
    }
};

/**
回溯算法
寻找去重的方法
**/