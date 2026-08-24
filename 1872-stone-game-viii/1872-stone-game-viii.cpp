#define ll long long
class Solution {
public:
    int stoneGameVIII(vector<int>& a) {
        ll n = a.size();
        vector<ll> pref(n), suff(n);
        pref[0] = a[0];
        for (ll i = 0; i < n - 1; i++) {
            pref[i + 1] = pref[i] + a[i + 1];
        }
        suff.back() = a.back();
        for (ll i = n - 1; i > 0; i--) {
            suff[i - 1] = suff[i] + a[i - 1];
        }
        ll sum = accumulate(a.begin(), a.end(), 0LL);
        vector<vector<ll>> dp(n, vector<ll>(2));
        ll mn = 0, mx = 0;
        for (ll i = n - 2; i >= 0; i--) {
            dp[i][1] = mx + sum;
            dp[i][0] = mn - sum;
            mx = max(mx, dp[i][0] - suff[i + 1]);
            mn = min(mn, dp[i][1] + suff[i + 1]);
        }
        return dp[0][1];
    }
};