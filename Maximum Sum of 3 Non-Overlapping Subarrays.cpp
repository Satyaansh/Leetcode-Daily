/*
Maximum Sum of 3 Non-Overlapping Subarrays
link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/?envType=daily-question&envId=2024-12-28
logic: left best + right best + search for the mid best linearily. A little too hard imo.
*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n - k + 1, 0); // Sums of subarrays of length k
        vector<int> left(n - k + 1, 0), right(n - k + 1, 0);
        
        // Calculate the sums of all subarrays of length k
        int currentSum = 0;
        for (int i = 0; i < n; ++i) {
            currentSum += nums[i];
            if (i >= k) currentSum -= nums[i - k];
            if (i >= k - 1) sum[i - k + 1] = currentSum;
        }

        // Calculate the best left index for each position
        int bestLeft = 0;
        for (int i = 0; i < sum.size(); ++i) {
            if (sum[i] > sum[bestLeft]) {
                bestLeft = i;
            }
            left[i] = bestLeft;
        }

        // Calculate the best right index for each position
        int bestRight = sum.size() - 1;
        for (int i = sum.size() - 1; i >= 0; --i) {
            if (sum[i] >= sum[bestRight]) {
                bestRight = i;
            }
            right[i] = bestRight;
        }

        // Find the best middle index
        vector<int> result(3, -1);
        int maxSum = 0;
        for (int mid = k; mid < sum.size() - k; ++mid) {
            int l = left[mid - k];
            int r = right[mid + k];
            int totalSum = sum[l] + sum[mid] + sum[r];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {l, mid, r};
            }
        }

        return result;
    }
};
