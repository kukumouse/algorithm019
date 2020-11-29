class Solution {
public:
    bool bfs(unordered_map<string,set<string>>& matrix,
    string beginWord,
    string endWord,
    unordered_set<string>& dict){
        unordered_set<string> visited;
        unordered_set<string> nextvisited;
        queue<string> que;
        que.push(beginWord);
        visited.insert(beginWord);
        bool isfound = false;
        while(!que.empty()){
            int size = que.size();
            for (int i = 0 ;i < size ;i++){
                string str = que.front();
                que.pop();
                if (!str.compare(endWord)) 
                    isfound = true;
                for (int j = 0 ; j < str.size(); j++){
                    string tmp = str;
                    for (int k = 0 ; k < 26 ; k++){
                        if (tmp[j] == 'a' + k) continue;
                        tmp[j] = 'a' + k ;
                        if (!visited.count(tmp) && dict.count(tmp)){
                            if (!nextvisited.count(tmp)){
                                nextvisited.insert(tmp);
                                que.push(tmp);
                            }
                            matrix[str].insert(tmp);
                        }
                    }
                }
            }
            if (isfound)
                break;
            visited.insert(nextvisited.begin(),nextvisited.end());
        }
        return isfound;
    }
    void dfs(vector<vector<string>>& ans,
    string beginWord,
    string endWord,
    vector<string>& path,
    unordered_map<string,set<string>>& matrix){

        if (!beginWord.compare(endWord)){
            ans.push_back(path);
            return;
        }
        if (!matrix.count(beginWord))
            return;
        for (auto c:matrix[beginWord]){
            path.push_back(c);
            dfs(ans,c,endWord,path,matrix);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(),wordList.end());
        unordered_map<string,set<string>> matrix;
        bool isfound = false;
        isfound = bfs(matrix,beginWord,endWord,dict);

        if (isfound){
            vector<string> path;
            path.push_back(beginWord);
            dfs(ans,beginWord,endWord,path,matrix);
        }
        return ans;
    }
};