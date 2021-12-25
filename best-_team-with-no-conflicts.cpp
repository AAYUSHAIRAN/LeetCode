vector<pair<int, int>> vect;
vector<int> vect1;
int n;
vector<vector<int>> dp;
bool sortcol(pair<int, int> &a, pair<int, int> &b){
    if(a.second < b.second)
        return true;
    else if(a.second == b.second)
        return (a.first < b.first);
    return false;
}
int rec(int level, int index){
    if(level == n)
        return 0;
    if(dp[level][index] != -1)
        return dp[level][index];
    
    else{
        int ans = rec(level+1, index);
        if(vect1[level] >= vect1[index]){
            ans = max(ans, vect1[level] + rec(level+1, level));
        }
        
        return dp[level][index] = ans;
    }
}
int solve(){
    dp = vector<vector<int>> (n+1, vector<int>(n+1, -1));
    int ans = 0;
    for(int i=0; i<n; ++i){
        ans = max(ans, vect1[i] + rec(i+1, i));
    }
    
    return ans;
}
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vect.clear();
        vect1.clear();
        n = scores.size();
        for(int i=0; i<n; ++i){
            vect.push_back({scores[i], ages[i]});
        }
        sort(vect.begin(), vect.end(), sortcol);
        for(auto val:vect){
            vect1.push_back(val.first);
        }
        return solve();
    }
};

// we will sort this according to age, and if 2 have same age -> will sort them according to 
// we need to select increasing sequence
// strictly increasing sequence
