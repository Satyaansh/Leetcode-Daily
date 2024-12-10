/*
Find Longest Special Substring That Occurs Thrice I
Link : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/?envType=daily-question&envId=2024-12-10
*/

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size(), ansSize = -1;
        string temp;
        unordered_map<string, int> m;
        //generate all substrings and store them with their frequencies
        for(int i = 0; i < n; i++) {
            temp = "";
            for(int j = i; j < n; j++) {
                temp += s[j];
                m[temp]++;
            }
        }
        //check if there are substrings which satisfy our criteria, if yes, ans = max(ans, curr)
        for(auto i : m) {
            //cout << i.first << " " << i.second << endl;
            if(i.second < 3 || (int)i.first.size() <= ansSize)
                continue;
            bool flag = true;
            for(int j = 1; j < i.first.size(); j++) {
                if(i.first[j] != i.first[j-1]) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ansSize = max(ansSize, (int)i.first.size());
        }
        return ansSize;
    }
};