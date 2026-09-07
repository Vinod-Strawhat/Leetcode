class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(26, 0);
        long long sumAll = 0; 

        for (char c : s) {
            int i = c - 'a';
            long long prev = dp[i];
            dp[i] = (sumAll + 1) % MOD; 
            sumAll = (sumAll - prev + dp[i] + MOD) % MOD; 
        }

        return (int) sumAll;
    }
};