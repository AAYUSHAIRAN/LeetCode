/**
* (level, profit, 1/2).
* Given state represents which player is in profit.
* and it returns the value obtained by player1 if evrything works well
*/
long n;
vector<long> rods;
long dp[21][5050][2];
long rec(long level, long profit, long key){
    if(level == n){
        if(profit == 0)
            return 0;
        else
            return -1e9;
    }
    
    if(dp[level][profit][key] != -1)
        return dp[level][profit][key];
    else{
        long ans = rec(level+1, profit, key);
        if(key == 0){
            ans = max(ans, rods[level] + rec(level+1, profit+rods[level], key));
            if(rods[level] >= profit)
                ans = max(ans, rec(level+1, rods[level]-profit, 1-key));
            else
                ans = max(ans, rec(level+1, profit-rods[level], key));
            return dp[level][profit][key] = ans;
        }
        else{
            ans = max(ans, rec(level+1, profit+rods[level], key));
            if(rods[level] >= profit)
                ans = max(ans, rods[level] + rec(level+1, rods[level]-profit, 1-key));
            else
                ans = max(ans, rods[level] + rec(level+1, profit-rods[level], key));
            return dp[level][profit][key] = ans;
        }
    }
}
long solve(){
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, 0);
}

class Solution {
public:
    int tallestBillboard(vector<int>& rods1) {
        rods.clear();
        for(auto val:rods1){
            rods.push_back(val);
        }
        n = rods.size();
        return solve();
    }
};
