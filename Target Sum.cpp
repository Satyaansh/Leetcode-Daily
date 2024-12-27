/*
Target Sum
Link: https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26
Logic: Dp with memoization. Also since negative indices might spring up, its better to use a map for memoization. Alternatively, can also use shift of origin to accomodate negatives
*/
class Solution {
public:
    int f(vector<int> &A, int ind, int n, int sum, int tar, unordered_map<string, int> &dp) {
        if(ind == n) {
            if(sum == tar)
                return 1;
            return 0;
        }
        string key = to_string(ind) + "." + to_string(sum);
        if(dp.find(key) != dp.end())
            return dp[key];
        int add = f(A, ind + 1, n, sum + A[ind], tar, dp);
        int sub = f(A, ind + 1, n, sum - A[ind], tar, dp);
        dp[key] = add + sub;
        return add + sub;
    }
    int findTargetSumWays(vector<int>& A, int tar) {
        int n = A.size();
        unordered_map<string, int> dp;
        int ans = f(A, 0, n, 0, tar, dp);
        return ans;
    }
};