/*
Reverse Odd Levels of Binary Tree
Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/?envType=daily-question&envId=2024-12-20
Logic: Just reverse every odd level, use BFS
*/
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int s = q.size();
            vector<TreeNode*> t;
            for(int i = 0; i < s; i++) {
                auto p = q.front();
                q.pop();
                t.push_back(p);
                if(p -> left)
                    q.push(p -> left);
                if(p -> right)
                    q.push(p -> right);
            }
            if(level % 2 == 1) {
                int st = 0, ed = s - 1;
                while(st < ed) {
                    swap(t[st] -> val, t[ed] -> val);
                    st++;
                    ed--;
                }
            }
            level++;
        }
        return root;
    }
};