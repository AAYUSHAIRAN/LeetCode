/**
* author: Aayush Airan
* https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
*/
int n;
vector<int> vect1, vect2;
vector<vector<int>> dp;
int rec(int level, int val){
    if(level == n)
        return 0;
    if(dp[level][val] != -1)
        return dp[level][val];
    else{
        int ans = 1e9;
        int curr_val1 = vect1[level];
        int curr_val2 = vect2[level];
        if(val){
            int prev_val1 = vect2[level-1];
            int prev_val2 = vect1[level-1];
            if(prev_val1 < curr_val1 && prev_val2 < curr_val2)
                ans = min(ans, rec(level+1, 0));
            if(prev_val1 < curr_val2 && prev_val2 < curr_val1)
                ans = min(ans, 1 + rec(level+1, 1));
        }
        else{
            int prev_val1 = vect1[level-1];
            int prev_val2 = vect2[level-1];
            if(prev_val1 < curr_val1 && prev_val2 < curr_val2)
                ans = min(ans, rec(level+1, 0));
            if(prev_val1 < curr_val2 && prev_val2 < curr_val1)
                ans = min(ans, 1 + rec(level+1, 1));
        }
        
        return dp[level][val] = ans;
    }
}
int solve(){
    dp = vector<vector<int>>(n+1, vector<int>(2, -1));
    return min(rec(1, 0), rec(1,1) + 1);
}
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vect1.clear();
        vect2.clear();
        n = nums1.size();
        for(auto val:nums1)
            vect1.push_back(val);
        for(auto val:nums2)
            vect2.push_back(val);
        return solve();
    }
};
