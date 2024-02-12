class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        int mi = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            mi = min(mi, (int)strs[i].size());
        }

        string t = "";
        
        for(int i = 0; i < mi; i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != strs[0][i]) return t;
            }
            t += strs[0][i];
        }
        
        return t;
    }
};
