/*
Construct String With Repeat Limit
Link: https://leetcode.com/problems/construct-string-with-repeat-limit/description/
Logic: Tricky to do in O(n) but if you are able to calculate filler character efficiently its very easy, just requires a bunch of checks
*/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26, 0);
        vector<pair<int, int>> A;
        string ans = "";
        int n = s.size();
        for(int i = 0; i <n; i++) {
            cnt[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 0)
                continue;
            A.push_back({i, cnt[i]});
        }
        sort(A.begin(), A.end(), greater<pair<int, int>>());
        for(int i = 0; i < A.size(); i++) {
            auto p = A[i];
            int next_idx = i + 1;
            //cout << p.first << " " << p.second << "\n";
            if(p.second <= repeatLimit) {
                for(int j = 0; j < p.second; j++)
                    ans += (char)p.first + 'a';
                continue;
            }
            else {
                while(p.second > 0) {
                    for(int j = 0; j < min(repeatLimit, p.second); j++) {
                        ans += (char)p.first + 'a';
                    }
                    p.second -= min(p.second, repeatLimit);
                    if(next_idx == A.size() || p.second == 0)
                        break;
                    ans += (char)A[next_idx].first + 'a';
                    A[next_idx].second--;
                    if(A[next_idx].second == 0)
                        next_idx++;
                }
            }
        }
        return ans;
    }
};