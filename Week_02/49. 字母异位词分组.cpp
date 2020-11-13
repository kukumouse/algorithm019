class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;
        for (string str : strs){
            string tmp = str;
            sort(tmp.begin(),tmp.end());
            map[tmp].push_back(str);
        }
        for (auto &n : map){
            ans.push_back(n.second);
        }
        return ans;
    }
};