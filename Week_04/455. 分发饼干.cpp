class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int p = 0;
        int j = 0;
        for (int i = 0 ; i < s.size() && j < g.size(); i++){
            if (g[j] <= s[i]){
                p++;
                j++;
            } 
        }
        return p;
    }
};