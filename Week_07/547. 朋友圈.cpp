class UF {
    // 记录连通分量个数
private:
    int count;
    // 存储若干棵树
    vector<int> parent;
    // 记录树的“重量”
    vector<int> size;

public:
    UF(int n) {
        count = n;
        parent.assign(n,0);
        size.assign(n,0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        return;
    }
    
    /* 将 p 和 q 连通 */
    void unio(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        
        // 小树接到大树下面，较平衡
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    /* 判断 p 和 q 是否互相连通 */
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        // 处于同一棵树上的节点，相互连通
        return rootP == rootQ;
    }

    /* 返回节点 x 的根节点 */
    int find(int x) {
        while (parent[x] != x) {
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    int get_count(){
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UF* uf = new UF(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] == 1)
                    uf->unio(i, j);
            }
        }
        
        return uf->get_count();

    }
};