class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step = 1;
        unordered_set<string> visited;
        queue<string> que;
        que.push(beginWord);
        visited.insert(beginWord);
        unordered_set<string> dict(wordList.begin(),wordList.end());

        while (!que.empty()){
            int size = que.size();
            for (int i = 0 ; i < size ;i++){
                string str = que.front();
                que.pop();
                if (!str.compare(endWord)) return step;
                for (int j = 0;j < str.size();j++){
                    string tmp = str;
                    for (int k=0;k< 26; k++){
                        if (tmp[j] == 'a' + k) continue;
                        tmp[j] = 'a' + k;
                        if (!visited.count(tmp) && dict.count(tmp)){
                            que.push(tmp);
                            visited.insert(tmp);
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
};