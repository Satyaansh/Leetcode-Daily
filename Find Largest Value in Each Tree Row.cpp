/*
Find Largest Value in Each Tree Row
Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/?envType=daily-question&envId=2024-12-25
Logic: standard problem, multiple ways
*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        if(root)
            q.push({root, 1});
        //ans.push_back(root -> val);
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(p.second > ans.size())
                ans.push_back(p.first -> val);
            else
                ans[p.second - 1] = max(ans[p.second - 1], p.first -> val);
            if(p.first -> left)
                q.push({p.first -> left, p.second + 1});
            if(p.first -> right)
                q.push({p.first -> right, p.second + 1});
        }
        return ans;
    }
};