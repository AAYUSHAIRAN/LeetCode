int num;
vector<int> dp;
int rec(int level){
    if(level == 1)
        return 0;
    if(dp[level] != -1)
        return dp[level];
    else{
        int ans = level;
        for(int i=2; i*i <= level; ++i){
            if(level%i == 0){
                int num1 = i, num2 = level/i;
                ans = min({ans, rec(num1) + num2, rec(num2) + num1});
            }
        }   
        return dp[level] = ans;
    }
}
int solve(){
    dp = vector<int>(num+1, -1);
    return rec(num);
}
class Solution {
public:
    int minSteps(int n) {
        num = n;
        return solve();
    }
};
