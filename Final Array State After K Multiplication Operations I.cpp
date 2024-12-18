/*
Final Array State After K Multiplication Operations I
Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/
Logic : Brute force it, small constraints
*/

class Solution {
public:
    vector<int> getFinalState(vector<int>& A, int k, int mult) {
        int mn_ele = INT_MAX, mn_idx = -1;
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < A.size(); j++) {
                if(A[j] < mn_ele) {
                    mn_ele = A[j];
                    mn_idx = j;
                }
            }
            A[mn_idx] *= mult;
            mn_idx = -1;
            mn_ele = INT_MAX;
        }
        return A;
    }
};