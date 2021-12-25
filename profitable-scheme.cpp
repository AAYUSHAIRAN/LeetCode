const long  mod = 1e9 + 7;
long minProfit, n;
vector<long> group, profit;
long dp[101][101][101];
long rec(long level, long leftMembers, long leftProfit){
    if(leftProfit < 0)
        leftProfit = 0;
    if(leftMembers < 0)
        return 0;
    if(level == group.size())
    {
        if(leftProfit <= 0)
            return 1;
        else
            return 0;
    }
    if(dp[level][leftMembers][leftProfit] != -1)
        return dp[level][leftMembers][leftProfit];
    else{
        long ans = rec(level+1, leftMembers, leftProfit);
        ans = ans + rec(level+1, leftMembers-group[level], leftProfit-profit[level]);
        ans %= mod;
        return dp[level][leftMembers][leftProfit] = ans;
    }
}
long solve(){
    memset(dp, -1, sizeof(dp));
    return rec(0, n, minProfit);
}
class Solution {
public:
    int profitableSchemes(int n1, int minProfit1, vector<int>& group1, vector<int>& profit1) {
        n = n1;
        minProfit = minProfit1;
        group.clear();
        profit.clear();
        for(auto val:group1)
            group.push_back(val);
        for(auto val:profit1)
            profit.push_back(val);
        return solve();
    }
};
