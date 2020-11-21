class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(),false);
        backTrack(ans,path,used,nums,0);
        return ans;
    }
    void backTrack(vector<vector<int>>& ans,vector<int>& path,vector<bool>& used,vector<int>& nums,int level){
        if (level == nums.size()){
            ans.push_back(path);
            return ;
        }
        for (int i = 0 ;i < nums.size(); i++){
            if (used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backTrack(ans,path,used,nums,level+1);
            path.pop_back();
            used[i] = false;
        }   
    }
};

/**
回溯算法。
重点在于排除重复值。
**/