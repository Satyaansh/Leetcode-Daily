/*
Best Sightseeing Pair
Link: https://leetcode.com/problems/best-sightseeing-pair/description/?envType=daily-question&envId=2024-12-27
Logic: A suffix precomputed array with A[j] - j stored, then a second pass to calculate max. Can be done in one pass but this seemed more intuitive
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size(), ans = INT_MIN;
        vector<int> pre(n, INT_MIN);
        pre[n-1] = A[n-1] - n + 1;
        for(int i = n - 2; i >= 0; i--) 
            pre[i] = max(pre[i+1], A[i] - i);
        for(int i = 0; i < n - 1; i++) 
            ans = max(ans, A[i] + i + pre[i+1]);
        return ans;
    }
};
