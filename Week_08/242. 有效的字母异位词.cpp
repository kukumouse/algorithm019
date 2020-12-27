class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<int,int> map;
        for (int i = 0 ;i<s.size();i++){
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        for (auto n : map){
            if (n.second != 0) 
                return false;
        }
        return true;
    }
};