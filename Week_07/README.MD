## 字典树
	
	应用场景，多用于字符的查找关联。
	字典树模板
	```
	class Trie {
    struct TrieNode {
        map<char, TrieNode*>child_table;
        int end;
        TrieNode(): end(0) {}
    };
        
	public:
	    /** Initialize your data structure here. */
	    Trie() {
	        root = new TrieNode();
	    }
	    
	    /** Inserts a word into the trie. */
	    void insert(string word) {
	        TrieNode *curr = root;
	        for (int i = 0; i < word.size(); i++) {
	            if (curr->child_table.count(word[i]) == 0)
	                curr->child_table[word[i]] = new TrieNode();
	                
	            curr = curr->child_table[word[i]];                
	        }
	        curr->end = 1;
	    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, 1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }
	private:
	    TrieNode* root;
	    bool find(string s, int exact_match) {
	        TrieNode *curr = root;
	        for (int i = 0; i < s.size(); i++) {
	            if (curr->child_table.count(s[i]) == 0)
	                return false;
	            else
	                curr = curr->child_table[s[i]];
	        }
	        
	        if (exact_match)
	            return (curr->end) ? true : false;
	        else
	            return true;
	    }
	};

## 并查集
	应用场景，查询两个对象是否在同一个集合中。
	并查集模板
	```
	class UnionFind {
	public:
	    UnionFind(vector<vector<char>>& grid) {
	        count = 0;
	        int m = grid.size();
	        int n = grid[0].size();
	        for (int i = 0; i < m; ++i) {
	            for (int j = 0; j < n; ++j) {
	                if (grid[i][j] == '1') {
	                    parent.push_back(i * n + j);
	                    ++count;
	                }
	                else {
	                    parent.push_back(-1);
	                }
	                rank.push_back(0);
	            }
	        }
	    }
	//递归
	    int find(int i) {
	        if (parent[i] != i) {
	            parent[i] = find(parent[i]);
	        }
	        return parent[i];
	    }
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }
    int getCount() const {
        return count;
    }
	private:
	    vector<int> parent;
	    vector<int> rank;
	    int count;
	};

## 双向BFS
	双向扩散的水波纹，使用2个队列往中间扩散，当两个队列相交时搜索完成。

## 启发式搜索
	股价函数，每搜索一步时候使用估价函数来找到最优的步骤。
	A*搜索
	```
	class Node {
	public:
	    int x;
	    int y;
	    bool operator< (const Node &A) {
		// 
	    }
	};

	void generate_related_nodes(Node &node) {
	    // 
	}

	void process(Node &node) {
	    // 
	}

	void AstarSearch(vector<vector<int>>& graph, Node& start, Node& end) {
	    vector<vector<bool> > visited(graph.size(), vector<bool>(graph[0].size(), false));
	    priority_queue<Node> q;
	    q.push(start);

	    while (!q.empty()) {
		Node cur = q.top();
		q.pop();
		visited[cur.x][cur.y] = true;


		process(node);
		vector<Node> nodes = generate_related_nodes(node) 
		for (auto node : nodes) {
		    if (!visited[node.x][node.y]) q.push(node);
		}
	    }

	    return ;
	}
## AVL树
	平衡二叉树，在每次插入和删除时候去平衡树，在每个节点记录平衡因子，1，0，-1 
	平衡因子 左树的高度 减去右树的高度 balance factor = {-1,0,1}
	空间上比较大，
	业务中如果查找比较大时建议使用。
	插入中的平衡法则为旋转操作
	1 左转
	2 左右转
	3 右转
	4 右左转
	提供了更快的查询，AVL需要存储额外更多的信息。

## 红黑树
	近似的平衡二叉树，常常用在数据库中插入删除。
	确保任何一个节点的左右树的高度差小于两倍
	1 每个节点要么是红色要么是黑色
	2 根节点是黑色
	3 每个叶子节点是黑色
	4 不能有相邻的两个红色节点
	5 从任何一个节点到其他每个叶子的所有路径都包含相同数目的黑色节点
	提供了更快的插入和删除操作，只需要1bit存储红黑。

	
	

	

