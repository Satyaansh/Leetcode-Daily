/*
Maximum Beauty of an Array After Applying Operation
Link : https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11
Logic : Sort + Sliding Window of 2 * k value
*/

class Solution {
public:
    int maximumBeauty(vector<int>& A, int k) {
        int n = A.size(), ans = 0, left = 0;
        sort(A.begin(), A.end());
         for (int right = 0; right < n; ++right) {
            while (A[right] - A[left] > 2 * k) {
                ++left; 
            }
            ans = max(ans, right - left + 1); 
        }
        return ans;
    }
};