int common(string s1, string s2){
    int i=0;
    for(; i<min(s1.size(), s2.size()); ++i){
        if(s1[i] != s2[i])
            break;
    }
    return i;
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int ans = strs[0].size();
        for(int i=1; i<n; ++i){
            ans = min(ans, common(strs[i], strs[i-1]));
        }
        string str = "";
        for(int i=0; i<ans; ++i)
            str += strs[0][i];
        return str;
    }
};
