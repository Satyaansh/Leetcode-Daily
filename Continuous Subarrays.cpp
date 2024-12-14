/*
Continuous Subarrays
Link : https://leetcode.com/problems/continuous-subarrays/description/?envType=daily-question&envId=2024-12-14
Logic : Using maps and sliding window, decreasing window when condition is violated. Another logic would be get a window, count all possible subarrays, decrease windows, subtract any common subarrays and repeat
*/

class Solution {
public:
    long long continuousSubarrays(vector<int>& A) {
        int n = A.size(), l = 0, r = 0;
        map<int, int> m;
        long long ans = 0;
        while(r < n) {
            m[A[r]]++;
            while(m.rbegin()->first - m.begin()->first > 2) {
                m[A[l]]--;
                if(m[A[l]] == 0)
                    m.erase(A[l]);
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
};