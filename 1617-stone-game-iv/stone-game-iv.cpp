class Solution {
public:
vector<int> dp;
bool solve(int n){
    if (n==0)
    return false;
    if (dp[n] != -1)
    return dp[n];
    for (int i=1; i<= n / i; i++){
        if (!solve(n-i*i)){
            return dp[n]=1;
        }
    }
    return dp[n]=0;
}
    bool winnerSquareGame(int n) {
        dp.assign(n+1, -1);
        return solve(n);        
    }
};