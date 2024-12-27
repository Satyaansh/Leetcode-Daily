/*
Max Chunks To Make Sorted
Link: https://leetcode.com/problems/max-chunks-to-make-sorted/description/?envType=daily-question&envId=2024-12-19
Logic: At every element check if the sum of elements and index cancel out each other, if yes, it means elements till here can be sorted independently 
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int n = A.size(), sum = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            sum += (A[i] - i);
            ans += (sum == 0);
        }
        return ans;
    }
};