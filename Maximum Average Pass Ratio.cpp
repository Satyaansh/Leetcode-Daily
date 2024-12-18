/*
Maximum Average Pass Ratio
Link : https://leetcode.com/problems/maximum-average-pass-ratio/description/
Logic : Using max heap to find out addition of one student in which class will result in the max net gain and subsequently gain in average
*/

class Solution {
public:
    double gain(int n, int d) {
        return (double)(n + 1) / (d + 1) - (double)n/d;
    }
    double maxAverageRatio(vector<vector<int>>& A, int ex) {
        int n = A.size();
        double ans = 0.0;
        priority_queue<pair<double, pair<int, int>>> q;
        for(int i = 0; i < n; i++) {
            q.push({gain(A[i][0], A[i][1]), {A[i][0], A[i][1]}});
        }
        for(int i = 0; i < ex; i++) {
            auto p = q.top();
            q.pop();
            q.push({gain(p.second.first + 1, p.second.second + 1), {p.second.first + 1, p.second.second + 1}});
        }
        while(!q.empty()) {
            auto p = q.top();
            q.pop();
            ans += (double)p.second.first/p.second.second;
        }
        return (ans / n);
    }
};