/*
Maximum Beauty of an Array After Applying Operation
Link : https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11
Logic : Simple line sweep algo
*/

class Solution {
public:
    int maximumBeauty(vector<int>& A, int k) {
        int n = A.size(), ans = 1;
        int mx = *max_element(A.begin(), A.end());
        vector<int> cnt (mx + k + 2, 0);
        for(int i = 0; i < n; i++) {
            cnt[max(0, A[i] - k)]++;
            cnt[A[i] + k + 1]--;
        }
        ans = max(ans, cnt[0]);
        for(int i = 1; i < cnt.size(); i++) {
            cnt[i] += cnt[i-1];
            ans = max(ans, cnt[i]);
        }
        return ans;
    }
};