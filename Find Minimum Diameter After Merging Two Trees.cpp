/*
Find Minimum Diameter After Merging Two Trees
Link: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/?envType=daily-question&envId=2024-12-24
Logic: max of d1, d2, longest path containing the joined nodes + 1. Also the algo to get dia for a undirected graph/tree is kinda nice
*/
class Solution {
public:
    vector<vector<int>> getAdjList(vector<vector<int>>& E) {
        int n = E.size();
        vector<vector<int>> A(n + 1, vector<int>());
        for(int i = 0; i < n; i++) {
            int u = E[i][0];
            int v = E[i][1];
            A[u].push_back(v);
            A[v].push_back(u);
        }
        return A;
    }
    pair<int, int> getFarNode(vector<vector<int>> &A, int src, int n) {
        queue<int> q;
        vector<bool> vis (n, false);
        int maxDist = 0;
        int farNode = src;
        q.push(src);
        vis[src] = true;
        while(!q.empty()) {
            int s = q.size();
            for(int i = 0; i < s; i++) {
                int curr = q.front();
                q.pop();
                farNode = curr;
                for(int node : A[curr]) {
                    if(!vis[node]) {
                        vis[node] = true;
                        q.push(node);
                    }
                }
            }
            if(!q.empty())
                maxDist++;
        }
        return {farNode, maxDist};
    }
    int getDia(vector<vector<int>> &A) {
        int n = A.size();
        auto [farNode, dist] = getFarNode(A, 0, n);
        auto [diaEnd, dia] = getFarNode(A, farNode, n);
        return dia;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& E1, vector<vector<int>>& E2) {
        vector<vector<int>> A1 = getAdjList(E1), A2 = getAdjList(E2);
        int d1 = getDia(A1);
        int d2 = getDia(A2);
        int maxDia = max(d1, d2);
        int ans = max(maxDia, 1 + max(d1/2, d1 - (d1/2) + max(d2/2, d2 - (d2/2))));
        return ans;
    }
};