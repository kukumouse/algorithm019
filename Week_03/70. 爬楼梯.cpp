class Solution {
public:
    unordered_map<int,int> map; //增加缓存 起到剪枝的作用
    int climbStairs(int n) {
        if (n < 2) return 1;
        if (map[n])
            return map[n];
        else
            map[n] = climbStairs(n-1) + climbStairs(n-2);
        
        return map[n];
    }
};

/**
通过学习递归之后，知道了递归的有点和缺点，
如果不进行优化而一味使用递归，
最终会造成傻递归做重复的无用功。
**/