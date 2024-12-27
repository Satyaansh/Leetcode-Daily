/*
Find Building Where Alice and Bob Can Meet
Link: https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/?envType=daily-question&envId=2024-12-22
Logic: Instead of going via queries, for each height(i) check if its the solution of any query XD
*/
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        vector<pair<int, int>> s;
        vector<int> ans(q.size(), -1);
        vector<vector<pair<int, int>>> nq(h.size());
        for(int i = 0; i < q.size(); i++) {
            int l = q[i][0];
            int r = q[i][1];
            if(l > r)
                swap(l, r);
            if(h[r] > h[l] || r == l)
                ans[i] = r;
            else
                nq[r].push_back({h[l], i});
        }
        for(int i = h.size() - 1; i >= 0; i--) {
            int ss = s.size();
            for(auto q : nq[i]) {
                int p = srch(q.first, s);
                if(p < ss && p >= 0)
                    ans[q.second] = s[p].second;
            }
            while(!s.empty() && h[i] >= s.back().first)
                s.pop_back();
            s.push_back({h[i], i});
        }
        return ans;
    }
    int srch(int tar, vector<pair<int, int>> &s) {
        int lo = 0, hi = s.size() - 1, ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(s[mid].first > tar) {
                ans = max(ans, mid);
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
};
