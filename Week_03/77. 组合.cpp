class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        backTrack(ans,path,n,k);
        return ans;
    }
    void backTrack(vector<vector<int>>& ans,vector<int>& path,int n,int k){
        if (k == path.size()){
            ans.push_back(path);
            return ;
        }
        for (int i = n ;i > 0 ;i--){
            if (i < k - path.size()) break;
            path.push_back(i);
            backTrack(ans,path,i-1,k);
            path.pop_back();
        }
    }
};
/**
回溯算法
当传递的子值需要一起下探时，回到上层递归时必须要重置子值。
以及回溯的优化，寻找剪枝条件。
**/