class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        if(needle.size()==haystack.size()){
            if(needle==haystack) return 0; else return -1;
        }
    int i=0;
while(i<haystack.size() && haystack.size()-1>=needle.size())
        {
            if(haystack.substr(i,needle.size())==needle) return i;
            i++;
        }
        return -1;
    }
};