class Solution {
public:
    void dfs(vector<string>& ans,int n,int left,int right,string path){
        if (left == n && right == n){
            ans.push_back(path);
            return ;
        }
        if (left < n) 
            dfs(ans,n,left+1,right,path+"(");
        if (left > right)
            dfs(ans,n,left,right+1,path+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int left = 0,right =0;
        dfs(ans,n,left,right,"");
        return ans;
    }

};

/**
使用分治算法解决括号对，
编写递归代码时先思考出口条件，
然后再针对题目来选择适当的解题方法。
**/