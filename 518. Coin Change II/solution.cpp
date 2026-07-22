class Solution {
public:
    int change(int amount, vector<int>& coins) { // 用dp
        vector<unsigned long long> dp(amount + 1, 0); //用unsigned long long，不然會runtime error
        dp[0] = 1; // dp要有初始值
        for(int coin : coins){
            for(int i = coin; i <= amount; i++){
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
