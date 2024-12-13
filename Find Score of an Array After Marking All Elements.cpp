/*
Find Score of an Array After Marking All Elements
Link : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13
Logic : Use map<int, vector<int>> and a visited boolean array, keep a counter and exit once you marked sizeof(A) elements. key point -> map is soretd by key by default
*/

class Solution {
public:
    long long findScore(vector<int>& A) {
        int n = A.size(), cnt = 0;
        long long ans = 0;
        map<int, vector<int>> m;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            m[A[i]].push_back(i);
        }
        for(auto i : m) {
            sort(i.second.begin(), i.second.end());
            for(int j = 0; j < i.second.size(); j++) {
                if(vis[i.second[j]] == true)
                    continue;
                ans += i.first;
                vis[i.second[j]] = true;
                cnt++;
                if(i.second[j] != 0 && vis[i.second[j] - 1] == false) {
                     vis[i.second[j] - 1] = true;
                     cnt++;
                }
                if(i.second[j] != n - 1 && vis[i.second[j] + 1] == false) {
                     vis[i.second[j] + 1] = true;
                     cnt++;
                }
                if(cnt == n)
                    return ans;
            }
        }
        return ans;
    }
};
